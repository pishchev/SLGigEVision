
// GigeConfigurator.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CGigeConfiguratorApp:
// Сведения о реализации этого класса: GigeConfigurator.cpp
//

class CGigeConfiguratorApp : public CWinApp
{
public:
	CGigeConfiguratorApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CGigeConfiguratorApp theApp;
