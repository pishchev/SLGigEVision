
// GigeConfiguratorDlg.h: файл заголовка
//

#pragma once
#include "GigeManager.hpp"

namespace Convert
{
	static std::string CStringToString(const CString& iCStr);
	static LPCTSTR StringToLPCTSTR(const std::string& iStr);
	static std::string IntToString(const int& iInt);
	static std::string DoubleToString(const double& iDouble);
	static int StringToInt(const std::string& iStr);
	static double StringToDouble(const std::string& iStr);
}

class Property
{
public:
	enum Type { Undefined, Int, Bool, Command, Float, Str, Enum };
	enum Visibility { Begginer, Expert, Guru, Invisible };
	enum AccessMode { RW, RO, WO, NA, NI };

	std::string _name;
	std::string _strValue;

	Type _type;
	Visibility _visibility;
	AccessMode _accessMode;

	bool _isChanged = false;
	bool _canBeChanged = true;
};

// Диалоговое окно CGigeConfiguratorDlg
class CGigeConfiguratorDlg : public CDialogEx
{
// Создание
public:
	CGigeConfiguratorDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GIGECONFIGURATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

// GigeConfiguration
private:
	enum Stage
	{
		ConfigStage,
		LibStage,
		InterfaceStage,
		DeviceStage,
		StreamStage,
		PropertiesStage,
		EditorStage
	};

	void InitConfigurator();
	void ShowConfigStage();
	void HideAll();
	void HideLayout(const std::vector<CWnd*>& iLayout);
	void ShowLayout(const std::vector<CWnd*>& iLayout);
	void FillProperties(size_t iStartIndex);
	void UpdateProperties();
	void GetProperties();
	void OpenEditor(size_t iPropertyIndex);

	GigeManager _gigeManager;

	std::vector<Property> _properties;
	Stage _stage;
	bool _useStartedConfig;

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	afx_msg void OnBnClickedNoStartConfig();
	CButton _startConfigButton;
	CButton _noStartConfigButton;
	std::vector<CWnd*> _configLayout;

	afx_msg void OnBnClickedLibFile();
	CEdit _libFile;
	CButton _applyLib;
	CStatic _libMessage;
	std::vector<CWnd*> _libLayout;

	afx_msg void OnBnClickedInterfaceApply();
	CComboBox _interfacesComboBox;
	CButton _applyInterface;
	CStatic _interfacesListMessage;
	std::vector<CWnd*> _interfaceLayout;

	afx_msg void OnBnClickedDeviceApply();
	CStatic _devicesMessage;
	CComboBox _devicesComboBox;
	CButton _applyDevice;
	std::vector<CWnd*> _deviceLayout;

	afx_msg void OnBnClickedStreamApply();
	CComboBox _streamsComboBox;
	CButton _applyStream;
	CStatic _streamsMessage;
	std::vector<CWnd*> _streamLayout;

	CEdit _propertyEdits[16];
	CEdit _valueEdits[16];
	CScrollBar _propertyScroll;
	std::vector<CWnd*> _propertyLayout;
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	CStatic _editorMessage;
	CEdit _editorPropertyName;
	CEdit _editorPropertyValue;
	CButton _applyEditor;
	std::vector<CWnd*> _editorLayout;

	CStatic _outputFileMessage;
	CEdit _outputFile;
	CButton _saveConfigButton;
	afx_msg void OnBnClickedSave();

	afx_msg void OnSetfocusEdit0();
	afx_msg void OnSetfocusEdit1();
	afx_msg void OnSetfocusEdit2();
	afx_msg void OnSetfocusEdit3();
	afx_msg void OnSetfocusEdit4();
	afx_msg void OnSetfocusEdit5();
	afx_msg void OnSetfocusEdit6();
	afx_msg void OnSetfocusEdit7();
	afx_msg void OnSetfocusEdit8();
	afx_msg void OnSetfocusEdit9();
	afx_msg void OnSetfocusEdit10();
	afx_msg void OnSetfocusEdit11();
	afx_msg void OnSetfocusEdit12();
	afx_msg void OnSetfocusEdit13();
	afx_msg void OnSetfocusEdit14();
	afx_msg void OnSetfocusEdit15();
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnBnClickedApplyEditor();
	afx_msg void OnBnClickedOk3();
	CComboBox _editorComboBox;
};
