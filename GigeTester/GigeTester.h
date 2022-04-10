
// GigeTester.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CGigeTesterApp:
// Сведения о реализации этого класса: GigeTester.cpp
//

class CGigeTesterApp : public CWinApp
{
public:
	CGigeTesterApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CGigeTesterApp theApp;
