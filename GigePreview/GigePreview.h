
// GigePreview.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CGigePreviewApp:
// Сведения о реализации этого класса: GigePreview.cpp
//

class CGigePreviewApp : public CWinApp
{
public:
	CGigePreviewApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CGigePreviewApp theApp;
