
// ConvertVcproj.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CConvertVcprojApp:
// �йش����ʵ�֣������ ConvertVcproj.cpp
//

class CConvertVcprojApp : public CWinAppEx
{
public:
	CConvertVcprojApp();

// ��д
	public:
	virtual BOOL InitInstance();

	CString m_StrVcxprojPath;

// ʵ��

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CConvertVcprojApp theApp;