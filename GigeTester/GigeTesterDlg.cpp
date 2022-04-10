
// GigeTesterDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "GigeTester.h"
#include "GigeTesterDlg.h"
#include "afxdialogex.h"
#include <chrono>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <string>


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CGigeTesterDlg



CGigeTesterDlg::CGigeTesterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GIGETESTER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGigeTesterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT5, _configMessage);
	DDX_Control(pDX, IDC_COMBO2, _configComboBox);
	DDX_Control(pDX, IDC_EDIT4, _secMessage);
	DDX_Control(pDX, IDC_EDIT6, _secEditor);
	DDX_Control(pDX, IDC_EDIT7, _fpsMessage);
	DDX_Control(pDX, IDC_EDIT8, _fpsEditor);
	DDX_Control(pDX, IDC_PROGRESS2, _progressBar);
}

BEGIN_MESSAGE_MAP(CGigeTesterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON4, &CGigeTesterDlg::OnBnClickedTest)
	ON_BN_CLICKED(IDC_BUTTON5, &CGigeTesterDlg::OnBnClickedSave)
END_MESSAGE_MAP()


// Обработчики сообщений CGigeTesterDlg

BOOL CGigeTesterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	Init();

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CGigeTesterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CGigeTesterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CGigeTesterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGigeTesterDlg::Init()
{
	_configMessage.SetWindowTextW(_T("Config name:"));
	_fpsMessage.SetWindowTextW(_T("FPS:"));
	_secMessage.SetWindowTextW(_T("Sec:"));
	_secEditor.SetWindowTextW(_T("5"));

	WIN32_FIND_DATAW wfd;
	HANDLE const hFind = FindFirstFileW(L"D:\\GigeVisionConfigurations\\*.gvc", &wfd);

	LONG configsCount = 0;
	if (INVALID_HANDLE_VALUE != hFind) {
		do {
			std::wstring wstrLib(&wfd.cFileName[0]);
			std::string strLib(wstrLib.begin(), wstrLib.end() - 4);
			_configComboBox.AddString(LPCTSTR(CA2T(strLib.c_str())));
		} while (NULL != FindNextFileW(hFind, &wfd));
		_configComboBox.SetCurSel(0);
		FindClose(hFind);
	}
}

void CGigeTesterDlg::Test(ISLGigEVisionCam* iCam)
{
	LONG width = 0;
	LONG height = 0;
	iCam->GetImageInfo(&width, &height);
	LONG payloadSize = width * height;
	LONG min = 0;
	LONG max = 0;
	size_t curIndex = 0;
	const auto image = new BYTE[(int)payloadSize];
	double timestamp = 0;

	CString sec;
	_secEditor.GetWindowTextW(sec);
	int secTest = std::atoi(std::string(CT2A(sec.GetString())).c_str());

	iCam->Start();
	auto time = std::chrono::steady_clock::now();
	auto start = std::chrono::steady_clock::now();
	auto diff = std::chrono::duration_cast<std::chrono::seconds>(time - start).count();

	while (diff < secTest) {
		iCam->GetFifoInfo(&min, &max);

		if (curIndex < (size_t)min + 2)
			curIndex = (size_t)max;

		if (iCam->GetImage((LONG)curIndex, eSLGEVImagePixelFormat::eIP_RAW, image, (LONG)payloadSize, &timestamp) == S_OK) {
			char str[156];  sprintf_s(str, "Frame=%d [%d..%d]\n", curIndex, min, max); OutputDebugStringA(str);
			curIndex++;
		}else Sleep(2);

		time = std::chrono::steady_clock::now();
		diff = std::chrono::duration_cast<std::chrono::seconds>(time - start).count();
		_progressBar.SetPos((double)diff/(double)secTest*100);
	}
	iCam->Stop();

	double fps = double(curIndex) / double(secTest);
	fps = int(100 * fps) / 100.0;
	std::string strFps = std::to_string(fps);
	_fpsEditor.SetWindowTextW(CA2T(strFps.c_str()));

	if (timestamp != 0)
		_config._tickSec = diff / timestamp;
}

std::string BSTRToString(const BSTR& iBSTR) {
	char str[MAX_PATH * 2];
	WideCharToMultiByte(CP_ACP, 0, iBSTR, -1, str, _countof(str), NULL, NULL);
	return std::string(str);
}

void CGigeTesterDlg::OnBnClickedTest()
{
	HRESULT coIn = CoInitializeEx(nullptr, COINIT::COINIT_MULTITHREADED);
	if (!SUCCEEDED(coIn))
		PostQuitMessage(0);

	ISLGigEVisionMgr* _mgr;
	ISLGigEVisionCam* _gige;

	HRESULT hr = CoCreateInstance(CLSID_SLGigEVisionMgr, nullptr, CLSCTX_INPROC_SERVER, IID_ISLGigEVisionMgr, (LPVOID*)&_mgr);
	if (!SUCCEEDED(hr))
		PostQuitMessage(0);

	CString configName;
	_configComboBox.GetLBText(_configComboBox.GetCurSel(), configName);

	LONG configCount = 0;
	_mgr->GetCamCount(&configCount);
	LONG index;
	for (index = 0; index < configCount; ++index) {
		BSTR name;
		_mgr->GetCamInfo(index, nullptr, nullptr, nullptr, &name, nullptr);
		if (BSTRToString(name) == std::string(CT2A(configName.GetString()))) {
			_config.ReadConfig(std::string(CT2A(configName.GetString())) + ".gvc");
			_config._tickSec = 1;
			_config.SaveConfig(_config._name + ".gvc");
			break;
		}
	}

	_mgr->GetCamObject(index, &_gige);
	Test(_gige);
}


void CGigeTesterDlg::OnBnClickedSave()
{
	CString sec;
	_fpsEditor.GetWindowTextW(sec);
	const auto fps = std::atof(std::string(CT2A(sec.GetString())).c_str());
	_config._fps = int(fps * 100)/ 100.0;
	_config.SaveConfig(_config._name + ".gvc");
	PostQuitMessage(0);
}
