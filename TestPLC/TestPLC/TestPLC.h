
// TestPLC.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestPLCApp: 
// �йش����ʵ�֣������ TestPLC.cpp
//

class CTestPLCApp : public CWinApp
{
public:
	CTestPLCApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestPLCApp theApp;