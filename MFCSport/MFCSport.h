
// MFCSport.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCSportApp: 
// �йش����ʵ�֣������ MFCSport.cpp
//

class CMFCSportApp : public CWinApp
{
public:
	CMFCSportApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCSportApp theApp;