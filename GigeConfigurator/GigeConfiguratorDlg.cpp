
// GigeConfiguratorDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "GigeConfigurator.h"
#include "GigeConfiguratorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// Диалоговое окно CGigeConfiguratorDlg



CGigeConfiguratorDlg::CGigeConfiguratorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GIGECONFIGURATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGigeConfiguratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, NO_START_CONFIG, _noStartConfigButton);
	DDX_Control(pDX, APPLY_LIB_FILE_, _applyLib);
	DDX_Control(pDX, INPUT_LIB_TEXT, _libMessage);
	DDX_Control(pDX, IDC_COMBO1, _interfacesComboBox);
	DDX_Control(pDX, IDC_BUTTON4, _applyInterface);
	DDX_Control(pDX, INTERFACES_LIST_MESSAGE, _interfacesListMessage);
	DDX_Control(pDX, DEVICES_MESSAGE, _devicesMessage);
	DDX_Control(pDX, IDC_COMBO2, _devicesComboBox);
	DDX_Control(pDX, IDC_BUTTON1, _applyDevice);
	DDX_Control(pDX, IDC_COMBO3, _streamsComboBox);
	DDX_Control(pDX, IDC_BUTTON2, _applyStream);
	DDX_Control(pDX, STREAM_MESSAGE, _streamsMessage);
	DDX_Control(pDX, IDC_EDIT2, _propertyEdits[0]);
	DDX_Control(pDX, IDC_EDIT3, _propertyEdits[1]);
	DDX_Control(pDX, IDC_EDIT4, _propertyEdits[2]);
	DDX_Control(pDX, IDC_EDIT5, _propertyEdits[3]);
	DDX_Control(pDX, IDC_EDIT6, _propertyEdits[4]);
	DDX_Control(pDX, IDC_EDIT7, _propertyEdits[5]);
	DDX_Control(pDX, IDC_EDIT8, _propertyEdits[6]);
	DDX_Control(pDX, IDC_EDIT9, _propertyEdits[7]);
	DDX_Control(pDX, IDC_EDIT10, _propertyEdits[8]);
	DDX_Control(pDX, IDC_EDIT11, _propertyEdits[9]);
	DDX_Control(pDX, IDC_EDIT12, _propertyEdits[10]);
	DDX_Control(pDX, IDC_EDIT13, _propertyEdits[11]);
	DDX_Control(pDX, IDC_EDIT14, _propertyEdits[12]);
	DDX_Control(pDX, IDC_EDIT15, _propertyEdits[13]);
	DDX_Control(pDX, IDC_EDIT16, _propertyEdits[14]);
	DDX_Control(pDX, IDC_EDIT17, _propertyEdits[15]);
	DDX_Control(pDX, IDC_EDIT18, _valueEdits[0]);
	DDX_Control(pDX, IDC_EDIT19, _valueEdits[1]);
	DDX_Control(pDX, IDC_EDIT20, _valueEdits[2]);
	DDX_Control(pDX, IDC_EDIT21, _valueEdits[3]);
	DDX_Control(pDX, IDC_EDIT22, _valueEdits[4]);
	DDX_Control(pDX, IDC_EDIT23, _valueEdits[5]);
	DDX_Control(pDX, IDC_EDIT24, _valueEdits[6]);
	DDX_Control(pDX, IDC_EDIT25, _valueEdits[7]);
	DDX_Control(pDX, IDC_EDIT26, _valueEdits[8]);
	DDX_Control(pDX, IDC_EDIT27, _valueEdits[9]);
	DDX_Control(pDX, IDC_EDIT28, _valueEdits[10]);
	DDX_Control(pDX, IDC_EDIT29, _valueEdits[11]);
	DDX_Control(pDX, IDC_EDIT30, _valueEdits[12]);
	DDX_Control(pDX, IDC_EDIT31, _valueEdits[13]);
	DDX_Control(pDX, IDC_EDIT32, _valueEdits[14]);
	DDX_Control(pDX, IDC_EDIT33, _valueEdits[15]);
	DDX_Control(pDX, IDC_SCROLLBAR1, _propertyScroll);
	DDX_Control(pDX, EDITOR_MESSAGE, _editorMessage);
	DDX_Control(pDX, IDC_EDIT34, _editorPropertyName);
	DDX_Control(pDX, IDC_EDIT36, _editorPropertyValue);
	DDX_Control(pDX, IDOK2, _applyEditor);
	DDX_Control(pDX, _OUTPUTFILE_MESSAGE, _outputFileMessage);
	DDX_Control(pDX, IDC_EDIT35, _outputFile);
	DDX_Control(pDX, IDOK, _saveConfigButton);
	DDX_Control(pDX, IDC_COMBO4, _editorComboBox);
	DDX_Control(pDX, IDC_COMBO5, _libsComboBox);
}

BEGIN_MESSAGE_MAP(CGigeConfiguratorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(NO_START_CONFIG, &CGigeConfiguratorDlg::OnBnClickedNoStartConfig)
	ON_WM_TIMER()
	ON_BN_CLICKED(APPLY_LIB_FILE_, &CGigeConfiguratorDlg::OnBnClickedLibFile)
	ON_BN_CLICKED(IDC_BUTTON1, &CGigeConfiguratorDlg::OnBnClickedDeviceApply)
	ON_BN_CLICKED(IDC_BUTTON4, &CGigeConfiguratorDlg::OnBnClickedInterfaceApply)
	ON_BN_CLICKED(IDC_BUTTON2, &CGigeConfiguratorDlg::OnBnClickedStreamApply)
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDOK, &CGigeConfiguratorDlg::OnBnClickedSave)
	ON_EN_SETFOCUS(IDC_EDIT18, &CGigeConfiguratorDlg::OnSetfocusEdit0)
	ON_EN_SETFOCUS(IDC_EDIT19, &CGigeConfiguratorDlg::OnSetfocusEdit1)
	ON_EN_SETFOCUS(IDC_EDIT20, &CGigeConfiguratorDlg::OnSetfocusEdit2)
	ON_EN_SETFOCUS(IDC_EDIT21, &CGigeConfiguratorDlg::OnSetfocusEdit3)
	ON_EN_SETFOCUS(IDC_EDIT22, &CGigeConfiguratorDlg::OnSetfocusEdit4)
	ON_EN_SETFOCUS(IDC_EDIT23, &CGigeConfiguratorDlg::OnSetfocusEdit5)
	ON_EN_SETFOCUS(IDC_EDIT24, &CGigeConfiguratorDlg::OnSetfocusEdit6)
	ON_EN_SETFOCUS(IDC_EDIT25, &CGigeConfiguratorDlg::OnSetfocusEdit7)
	ON_EN_SETFOCUS(IDC_EDIT26, &CGigeConfiguratorDlg::OnSetfocusEdit8)
	ON_EN_SETFOCUS(IDC_EDIT27, &CGigeConfiguratorDlg::OnSetfocusEdit9)
	ON_EN_SETFOCUS(IDC_EDIT28, &CGigeConfiguratorDlg::OnSetfocusEdit10)
	ON_EN_SETFOCUS(IDC_EDIT29, &CGigeConfiguratorDlg::OnSetfocusEdit11)
	ON_EN_SETFOCUS(IDC_EDIT30, &CGigeConfiguratorDlg::OnSetfocusEdit12)
	ON_EN_SETFOCUS(IDC_EDIT31, &CGigeConfiguratorDlg::OnSetfocusEdit13)
	ON_EN_SETFOCUS(IDC_EDIT32, &CGigeConfiguratorDlg::OnSetfocusEdit14)
	ON_EN_SETFOCUS(IDC_EDIT33, &CGigeConfiguratorDlg::OnSetfocusEdit15)
	ON_WM_MOUSEWHEEL()
	ON_BN_CLICKED(IDOK2, &CGigeConfiguratorDlg::OnBnClickedApplyEditor)
	ON_BN_CLICKED(IDOK3, &CGigeConfiguratorDlg::OnBnClickedOk3)
END_MESSAGE_MAP()


// Обработчики сообщений CGigeConfiguratorDlg

BOOL CGigeConfiguratorDlg::OnInitDialog()
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
	InitConfigurator();

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CGigeConfiguratorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CGigeConfiguratorDlg::OnPaint()
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
HCURSOR CGigeConfiguratorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

std::string Convert::CStringToString(const CString& iCStr)
{
	return CT2A(iCStr.GetString());
}

LPCTSTR Convert::StringToLPCTSTR(const std::string& iStr)
{
	return CA2T(iStr.c_str());
}

std::string Convert::IntToString(const int& iInt)
{
	return std::to_string(iInt);
}

std::string Convert::DoubleToString(const double& iDouble)
{
	return std::to_string(iDouble);
}

int Convert::StringToInt(const std::string& iStr)
{
	return std::stoi(iStr);
}

double Convert::StringToDouble(const std::string& iStr)
{
	return std::stof(iStr);
}

void CGigeConfiguratorDlg::InitConfigurator()
{
	SetTimer(1, 1000, 0);

	_configLayout.push_back(&_startConfigButton);
	_configLayout.push_back(&_noStartConfigButton);

	_libLayout.push_back(&_libMessage);
	_libLayout.push_back(&_libsComboBox);
	_libLayout.push_back(&_applyLib);

	WIN32_FIND_DATAW wfd;
	HANDLE const hFind = FindFirstFileW(L"*.cti", &wfd);

	LONG configsCount = 0;
	if (INVALID_HANDLE_VALUE != hFind) {
		do {
			std::wstring wstrLib(&wfd.cFileName[0]);
			std::string strLib(wstrLib.begin(), wstrLib.end());
			_libsComboBox.AddString(Convert::StringToLPCTSTR(strLib));
		} while (NULL != FindNextFileW(hFind, &wfd));
		_libsComboBox.SetCurSel(0);
		FindClose(hFind);
	}

	_interfaceLayout.push_back(&_interfacesComboBox);
	_interfaceLayout.push_back(&_interfacesListMessage);
	_interfaceLayout.push_back(&_applyInterface);

	_deviceLayout.push_back(&_devicesComboBox);
	_deviceLayout.push_back(&_devicesMessage);
	_deviceLayout.push_back(&_applyDevice);

	_streamLayout.push_back(&_streamsComboBox);
	_streamLayout.push_back(&_applyStream);
	_streamLayout.push_back(&_streamsMessage);


	for (size_t i = 0; i < 16; ++i)
	{
		_propertyLayout.push_back(&_propertyEdits[i]);
		_propertyLayout.push_back(&_valueEdits[i]);
	}
	_propertyLayout.push_back(&_propertyScroll);
	_propertyLayout.push_back(&_outputFile);
	_propertyLayout.push_back(&_outputFileMessage);
	_propertyLayout.push_back(&_saveConfigButton);

	_editorLayout.push_back(&_editorMessage);
	_editorLayout.push_back(&_editorPropertyName);
	_editorLayout.push_back(&_editorPropertyValue);
	_editorLayout.push_back(&_editorComboBox);
	_editorLayout.push_back(&_applyEditor);

	_stage = Stage::ConfigStage;
	ShowConfigStage();
}

void CGigeConfiguratorDlg::ShowConfigStage()
{
	_stage >= Stage::ConfigStage ? ShowLayout(_configLayout) : HideLayout(_configLayout);
	_stage >= Stage::LibStage ? ShowLayout(_libLayout) : HideLayout(_libLayout);
	_stage >= Stage::InterfaceStage ? ShowLayout(_interfaceLayout) : HideLayout(_interfaceLayout);
	_stage >= Stage::DeviceStage ? ShowLayout(_deviceLayout) : HideLayout(_deviceLayout);
	_stage >= Stage::StreamStage ? ShowLayout(_streamLayout) : HideLayout(_streamLayout);
	_stage >= Stage::PropertiesStage ? ShowLayout(_propertyLayout) : HideLayout(_propertyLayout);
	_stage >= Stage::EditorStage ? ShowLayout(_editorLayout) : HideLayout(_editorLayout);
}

void CGigeConfiguratorDlg::HideAll()
{
	HideLayout(_configLayout);
	HideLayout(_libLayout);
	HideLayout(_interfaceLayout);
	HideLayout(_deviceLayout);
	HideLayout(_streamLayout);
	HideLayout(_propertyLayout);
	HideLayout(_editorLayout);
}

void CGigeConfiguratorDlg::HideLayout(const std::vector<CWnd*>& iLayout)
{
	for (size_t i = 0; i < iLayout.size(); ++i)
		(*iLayout[i]).ShowWindow(SW_HIDE);
}

void CGigeConfiguratorDlg::ShowLayout(const std::vector<CWnd*>& iLayout)
{
	for (size_t i = 0; i < iLayout.size(); ++i)
		(*iLayout[i]).ShowWindow(SW_SHOW);
}

void CGigeConfiguratorDlg::FillProperties(size_t iStartIndex)
{
	for (size_t i = 0; i < 16; ++i)
	{
		size_t propIndex = i + iStartIndex;

		_propertyEdits[i].SetWindowTextW(Convert::StringToLPCTSTR(_properties[propIndex]._name));
		_valueEdits[i].SetWindowTextW(Convert::StringToLPCTSTR(_properties[propIndex]._strValue));

		if (_properties[propIndex]._accessMode != Property::RW ||
			!_properties[propIndex]._canBeChanged)
			_valueEdits[i].SetReadOnly(1);
		else
			_valueEdits[i].SetReadOnly(0);
	}
}

void CGigeConfiguratorDlg::UpdateProperties()
{

}

void CGigeConfiguratorDlg::GetProperties()
{
	_properties.clear();

	for (uint32_t i = 0; i < _gigeManager.GetNodesSize() && i < 473; ++i)
	{
		Property prop;
		prop._name = _gigeManager.GetNodeName(i);
		switch (_gigeManager.GetNodeType(i))
		{
			case GigeManager::Int: 
			{
				prop._type = Property::Int;
				int64_t intVal;
				if (!_gigeManager.GetIntNode(prop._name, intVal)) continue;
				prop._strValue = Convert::IntToString((int)intVal);
				break;
			}
			case GigeManager::Bool:
			{
				prop._type = Property::Bool;
				bool val;
				if (!_gigeManager.GetBoolNode(prop._name, val)) continue;
				prop._strValue = val ? "1" : "0";
				break;
			}
			case GigeManager::Command:
			{
				prop._type = Property::Command;
				bool val;
				if (!_gigeManager.GetCommandNode(prop._name, val)) continue;
				prop._strValue = val ? "1" : "0";
				break;
			}
			case GigeManager::Float:
			{
				prop._type = Property::Float;
				double val;
				if (!_gigeManager.GetFloatNode(prop._name, val)) continue;
				prop._strValue = Convert::DoubleToString(val);
				break;
			}
			case GigeManager::String:
			{
				prop._type = Property::Str;
				if (!_gigeManager.GetStrNode(prop._name, prop._strValue)) continue;
				prop._canBeChanged = false;
				break;
			}
			case GigeManager::Enumeration:
			{
				prop._type = Property::Enum;
				if (!_gigeManager.GetEnumStrNode(prop._name, prop._strValue)) continue;
				break;
			}
			default: 
			{
				continue;
			}
		}

		if (_gigeManager.GetNodeAccess(i) == 4)
			prop._accessMode = Property::RW;
		else 
			prop._accessMode = Property::RO;

		_properties.push_back(prop);
	}

	const auto maxPos = (int)_properties.size() - 16;
	_propertyScroll.SetScrollRange(0, maxPos >= 0 ? maxPos : 0);
}

void CGigeConfiguratorDlg::OpenEditor(size_t iPropertyIndex)
{
	const auto& prop = _properties[_propertyScroll.GetScrollPos() + iPropertyIndex];
	
	if (prop._accessMode != Property::RW || !prop._canBeChanged)
	{
		_stage = Stage::PropertiesStage;
		ShowConfigStage();
	}
	else
	{
		for (int i = _editorComboBox.GetCount(); i >= 0; --i)
			_editorComboBox.DeleteString(i);

		_editorPropertyName.SetWindowTextW(Convert::StringToLPCTSTR(prop._name));

		_stage = Stage::EditorStage;
		ShowConfigStage();

		if (prop._type == Property::Enum)
		{
			std::string curName;
			_gigeManager.GetEnumNodeName(prop._name, curName);
			
			for (uint32_t i = 0; i < _gigeManager.GetEnumStrEntrySize(prop._name); i++)
			{
				_editorComboBox.AddString(Convert::StringToLPCTSTR(_gigeManager.GetEnumStrEntryName(prop._name, i)));
			}
			for (uint32_t i = 0; i < _gigeManager.GetEnumStrEntrySize(prop._name); i++)
			{
				CString name;
				_editorComboBox.GetLBText(i, name);
				if (Convert::CStringToString(name) == curName)
					_editorComboBox.SetCurSel(i);
			}

			_editorPropertyValue.ShowWindow(SW_HIDE);
		}
		else 
		{
			_editorPropertyValue.SetWindowTextW(Convert::StringToLPCTSTR(prop._strValue));
			_editorComboBox.ShowWindow(SW_HIDE);
		}
	}
}

void CGigeConfiguratorDlg::OnBnClickedNoStartConfig()
{
	_stage = LibStage;
	ShowConfigStage();
}


void CGigeConfiguratorDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	CDialogEx::OnTimer(nIDEvent);
}


void CGigeConfiguratorDlg::OnBnClickedLibFile()
{
	CString libFile;
	_libsComboBox.GetLBText(_libsComboBox.GetCurSel(), libFile);
	_gigeManager.UseLib(Convert::CStringToString(libFile));

	for (uint32_t i = 0; i < _gigeManager.GetIntefacesSize(); i++) 
	{
		std::string iface = _gigeManager.GetInterfaceName(i);
		_interfacesComboBox.AddString(Convert::StringToLPCTSTR(iface));
	}

	if (_gigeManager.GetIntefacesSize() != 0)
		_interfacesComboBox.SetCurSel(0);

	_stage = InterfaceStage;
	ShowConfigStage();
}


void CGigeConfiguratorDlg::OnBnClickedDeviceApply()
{
	CString device;
	_devicesComboBox.GetLBText(_devicesComboBox.GetCurSel(), device);
	_gigeManager.UseDevice(Convert::CStringToString(device));

	for (uint32_t i = 0; i < _gigeManager.GetStreamsSize(); i++)
	{
		std::string stream = _gigeManager.GetStreamName(i);
		_streamsComboBox.AddString(Convert::StringToLPCTSTR(stream));
	}

	if (_gigeManager.GetStreamsSize() != 0)
		_streamsComboBox.SetCurSel(0);

	_stage = Stage::StreamStage;
	ShowConfigStage();
}


void CGigeConfiguratorDlg::OnBnClickedInterfaceApply()
{
	CString interfaceStr;
	_interfacesComboBox.GetLBText(_interfacesComboBox.GetCurSel(), interfaceStr);
	_gigeManager.UseInterface(Convert::CStringToString(interfaceStr));

	for (uint32_t i = 0; i < _gigeManager.GetDevicesSize(); i++)
	{
		std::string dev = _gigeManager.GetDeviceName(i);
		_devicesComboBox.AddString(Convert::StringToLPCTSTR(dev));
	}

	if (_gigeManager.GetDevicesSize() != 0)
		_devicesComboBox.SetCurSel(0);

	_stage = Stage::DeviceStage;
	ShowConfigStage();
}


void CGigeConfiguratorDlg::OnBnClickedStreamApply()
{
	CString stream;
	_streamsComboBox.GetLBText(_streamsComboBox.GetCurSel(), stream);
	_gigeManager.UseStream(Convert::CStringToString(stream));

	_gigeManager.CameraInit();
	GetProperties();
	FillProperties(0);

	_stage = Stage::PropertiesStage;
	ShowConfigStage();
}

void CGigeConfiguratorDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	switch (nSBCode)
	{
		case SB_LINEUP: 
		{
			const auto newPos = _propertyScroll.GetScrollPos() - 1;
			if (newPos >= 0)
				_propertyScroll.SetScrollPos(newPos);
			break;
		}
		case SB_LINEDOWN:
		{
			const auto newPos = _propertyScroll.GetScrollPos() + 1;
			if (newPos <= _properties.size() - 16)
				_propertyScroll.SetScrollPos(newPos);
			break;
		}
		case SB_THUMBTRACK:
		{
			_propertyScroll.SetScrollPos(nPos);
			break;
		}
		case SB_THUMBPOSITION:
		{
			_propertyScroll.SetScrollPos(nPos);
			break;
		}
	}

	FillProperties(_propertyScroll.GetScrollPos());
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CGigeConfiguratorDlg::OnBnClickedSave()
{
	CString outputFile;
	_outputFile.GetWindowTextW(outputFile);
	const auto outputStr = Convert::CStringToString(outputFile);

	if (outputStr.empty())
		return;

	int64_t tmp = 0;
	_gigeManager.GetIntNode("Width", tmp);
	_gigeManager.SetIntNode("Width", tmp);
	_gigeManager.GetIntNode("Height", tmp);
	_gigeManager.SetIntNode("Height", tmp);

	_gigeManager.SaveConfig(outputStr + ".gvc");
	PostQuitMessage(0);
}


void CGigeConfiguratorDlg::OnSetfocusEdit0() { OpenEditor(0); }
void CGigeConfiguratorDlg::OnSetfocusEdit1() { OpenEditor(1); }
void CGigeConfiguratorDlg::OnSetfocusEdit2() { OpenEditor(2); }
void CGigeConfiguratorDlg::OnSetfocusEdit3() { OpenEditor(3); }
void CGigeConfiguratorDlg::OnSetfocusEdit4() { OpenEditor(4); }
void CGigeConfiguratorDlg::OnSetfocusEdit5() { OpenEditor(5); }
void CGigeConfiguratorDlg::OnSetfocusEdit6() { OpenEditor(6); }
void CGigeConfiguratorDlg::OnSetfocusEdit7() { OpenEditor(7); }
void CGigeConfiguratorDlg::OnSetfocusEdit8() { OpenEditor(8); }
void CGigeConfiguratorDlg::OnSetfocusEdit9() { OpenEditor(9); }
void CGigeConfiguratorDlg::OnSetfocusEdit10() { OpenEditor(10); }
void CGigeConfiguratorDlg::OnSetfocusEdit11() { OpenEditor(11); }
void CGigeConfiguratorDlg::OnSetfocusEdit12() { OpenEditor(12); }
void CGigeConfiguratorDlg::OnSetfocusEdit13() { OpenEditor(13); }
void CGigeConfiguratorDlg::OnSetfocusEdit14() { OpenEditor(14); }
void CGigeConfiguratorDlg::OnSetfocusEdit15() { OpenEditor(15); }


BOOL CGigeConfiguratorDlg::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	if (_stage >= Stage::PropertiesStage)
	{
		const auto scrollFlag = zDelta > 0 ? SB_LINEUP : SB_LINEDOWN;
		OnVScroll(scrollFlag, 0, nullptr);
	}

	return CDialogEx::OnMouseWheel(nFlags, zDelta, pt);
}


void CGigeConfiguratorDlg::OnBnClickedApplyEditor()
{
	Property prop;

	CString name, value;

	_editorPropertyName.GetWindowTextW(name);
	for (size_t i = 0; i < _properties.size(); ++i)
	{
		if (_properties[i]._name == Convert::CStringToString(name))
		{
			prop = _properties[i];
			break;
		}
	}

	if (prop._type == Property::Enum)
		_editorComboBox.GetLBText(_editorComboBox.GetCurSel(), value);
	else
		_editorPropertyValue.GetWindowTextW(value);

	const auto strVal = Convert::CStringToString(value);		
	//if (strVal == prop._strValue)
	//	return;
	if (prop._type == Property::Int)
	{
		_gigeManager.SetIntNode(prop._name, Convert::StringToInt(strVal));
	}
	else if (prop._type == Property::Float)
	{
		_gigeManager.SetFloatNode(prop._name, Convert::StringToDouble(strVal));
	}
	else if (prop._type == Property::Bool)
	{
		_gigeManager.SetBoolNode(prop._name, strVal == "1" ? true : false);
	}
	else if (prop._type == Property::Enum)
	{
		_gigeManager.SetEnumStrNode(prop._name, strVal);
	}

	GetProperties();
	FillProperties(_propertyScroll.GetScrollPos());
	_stage = Stage::PropertiesStage;
}



void CGigeConfiguratorDlg::OnBnClickedOk3()
{
	PostQuitMessage(0);
}
