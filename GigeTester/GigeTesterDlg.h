
// GigeTesterDlg.h: файл заголовка
//

#pragma once

#include "../SLGigEVision/SLGigEVision_i.h"
#include "../SLGigEVision/SLGigEVision_i.c"

#include "Configurator.hpp"

// Диалоговое окно CGigeTesterDlg
class CGigeTesterDlg : public CDialogEx
{
// Создание
public:
	CGigeTesterDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GIGETESTER_DIALOG };
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
public:

	void Init();
	void Test(ISLGigEVisionCam* iCam);

	Configurator _config;
	CEdit _configMessage;
	CComboBox _configComboBox;
	CEdit _secMessage;
	CEdit _secEditor;
	afx_msg void OnBnClickedTest();
	CEdit _fpsMessage;
	CEdit _fpsEditor;
	CProgressCtrl _progressBar;
	afx_msg void OnBnClickedSave();
};
