
// GigePreviewDlg.h: файл заголовка
//

#pragma once

#include <iostream>
#include <iomanip>
#include <objbase.h>
#include <comdef.h>
#include <string>

#include "../SLGigEVision/SLGigEVision_i.h"
#include "../SLGigEVision/SLGigEVision_i.c"

// Диалоговое окно CGigePreviewDlg
class CGigePreviewDlg : public CDialogEx
{
// Создание
public:
	CGigePreviewDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GIGEPREVIEW_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	enum Stage { ConfigChoosing, Play };

	void Init();
	void InitGigeDLL();
	void InitDialogComponents();
	void HideDialogComponents();
	void ShowImage();
	

	ISLGigEVisionMgr* _mgr;
	ISLGigEVisionCam* _gige;
	size_t _payloadSize;
	size_t _width;
	size_t _height;
	size_t _curIndex = 0;
	double _timestamp = 0;
	unsigned char* _image;
	bool _started;

	LONG _min = 0;
	LONG _max = 0;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit _configMessage;
	CButton _configApply;
	afx_msg void OnBnClickedApplyConfig();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CButton _exitButton;
	CComboBox _configComboBox;
};
