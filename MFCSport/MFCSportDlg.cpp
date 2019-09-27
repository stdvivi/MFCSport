
// MFCSportDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCSport.h"
#include "MFCSportDlg.h"
#include "afxdialogex.h"

#include <MsHTML.h> 

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCSportDlg �Ի���



CMFCSportDlg::CMFCSportDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCSportDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCSportDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, m_Explorer);
}

BEGIN_MESSAGE_MAP(CMFCSportDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCSportDlg::OnBnClickedButton1)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_CHECK1, &CMFCSportDlg::OnBnClickedCheck1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDOK, &CMFCSportDlg::OnOK)
	ON_BN_CLICKED(IDCANCEL, &CMFCSportDlg::OnCancel)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CMFCSportDlg ��Ϣ�������

BOOL CMFCSportDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	CComVariant vtUrl("http://www.zhtyzx.cn/zhh_sports/view/item/item_main.jsp");
	CComVariant vtEmpty;  //NULL
	m_Explorer.Navigate2(&vtUrl, &vtEmpty, &vtEmpty, &vtEmpty, &vtEmpty);//��ָ������ҳ

	SetDlgItemText(IDC_EDITURL, _T("http://www.zhtyzx.cn/zhh_sports/view/item/item_main.jsp"));

	CTime expire(2020, 12, 31, 23, 59, 59);
	CTime now = CTime::GetCurrentTime();
	if (now > expire)
	{
		CButton* pCheck = (CButton*)GetDlgItem(IDC_CHECK1);
		//pCheck->EnableWindow(FALSE);
		pCheck->ShowWindow(FALSE);
		CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON1);
		//pButton->EnableWindow(FALSE);
		pButton->ShowWindow(FALSE);
	}

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCSportDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCSportDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCSportDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCSportDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CComQIPtr<IHTMLDocument2> spDoc = m_Explorer.get_Document();
	CComDispatchDriver spScript;
	spDoc->get_Script(&spScript);

	CComVariant var1("2");
	CComVariant var2 = 20, varRet;
	spScript.Invoke1(L"next", &var1, &varRet);
	//spDoc->get_frames
	//spScript.Invoke0(L"next2", &varRet);
}


void CMFCSportDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
	m_Explorer.MoveWindow(0, 80, cx, cy - 80);
}
BEGIN_EVENTSINK_MAP(CMFCSportDlg, CDialogEx)
	ON_EVENT(CMFCSportDlg, IDC_EXPLORER1, 259, CMFCSportDlg::DocumentCompleteExplorer1, VTS_DISPATCH VTS_PVARIANT)
END_EVENTSINK_MAP()


void CMFCSportDlg::DocumentCompleteExplorer1(LPDISPATCH pDisp, VARIANT* URL)
{
	// TODO:  �ڴ˴������Ϣ����������
	IHTMLDocument2* pHTMLDoc = (IHTMLDocument2*)m_Explorer.get_Document();
	if (pHTMLDoc != NULL)
	{
		IHTMLWindow2* pHTMLWnd;
		pHTMLDoc->get_parentWindow(&pHTMLWnd);
		if (pHTMLWnd != NULL)
		{
			CString js_code;
			js_code = L"javascript:document.body.style.overflow = 'auto';javascript:document.documentElement.style.overflow = 'auto'; void(0);";//�˴�Ϊʵ��д���javascript����  
			//js_code.Format(L"goToLocation('%s');",JScode);//JS������+����    
			VARIANT  ret;
			ret.vt = VT_EMPTY;
			pHTMLWnd->execScript(js_code.AllocSysString(), L"Javascript", &ret);//ִ��javascript����

			CComBSTR bstrScript("javascript:function next2() {"
				"$(\"#reginCode_div\").html(\"\");"
				"$(\"#item_remark\").html(item_remark);"
				"$(\"#personContent\").removeAttr(\"style\");"
				"$(\"#orderContent\").css(\"display\", \"none\");"
				"try{"
				"window.parent.window.dyniframesize('Comments');"
				"}catch(e){}"
				"}");
			pHTMLWnd->execScript(bstrScript, L"Javascript", &ret);
		}
	}
	//m_Explorer.ShowScrollBar(SB_BOTH);
}


BOOL CMFCSportDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  �ڴ����ר�ô����/����û���
	if (WM_KEYDOWN == pMsg->message)
	{
		CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDITURL);
		ASSERT(pEdit);
		if (pMsg->hwnd == pEdit->GetSafeHwnd() && VK_RETURN == pMsg->wParam)
		{
			CString url;
			GetDlgItemText(IDC_EDITURL, url);			
			CComVariant vtUrl{ url };
			CComVariant vtEmpty;  //NULL
			m_Explorer.Navigate2(&vtUrl, &vtEmpty, &vtEmpty, &vtEmpty, &vtEmpty);//��ָ������ҳ
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CMFCSportDlg::OnBnClickedCheck1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CButton* pCheck = (CButton*)GetDlgItem(IDC_CHECK1);
	if (pCheck->GetCheck())
	{
		SetTimer(1, 500, NULL);
	}
	else
	{
		KillTimer(1);
	}
}


void CMFCSportDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	HRESULT hr;
	CComQIPtr<IHTMLInputElement> spInputElement;
	CComQIPtr<IHTMLDocument3> spDocument = m_Explorer.get_Document();
	CComPtr<IHTMLElement> spElement;
	CComPtr<IHTMLElementCollection> spCol;
	spDocument->getElementsByTagName(L"a", &spCol);//ͨ��ID���Ԫ�ض������spElement�У������ID��100���������Ϳ��ԶԸö�����в���  
	if (spCol == NULL)//����ID֮��������ж��¸�ID�Ƿ����  
	{
		//MessageBox(L"a������");
		return;
	}
	long count;
	spCol->get_length(&count);
	for (int i = 0; i < count; i++)
	{
		CComVariant varName(i);
		varName.ChangeType(VT_UINT);
		CComVariant varIndex;
		CComPtr<IDispatch>pDisp;

		hr = spCol->item(varName, varIndex, &pDisp);
		if (SUCCEEDED(hr))
		{
			//CComQIPtr<IHTMLElement, &IID_IHTMLElement>pElement(pDisp);
			CComQIPtr<IHTMLAnchorElement, &IID_IHTMLAnchorElement>pElement(pDisp);

			if (pElement.p != NULL)
			{
				CComBSTR bstrHref;

				hr = pElement->get_href(&bstrHref);

				//pElement->get_tagName(&bstrHref);
				CString href(bstrHref);
				if (href == "javascript:next('2');")
				{
					KillTimer(1);
					CButton* pCheck = (CButton*)GetDlgItem(IDC_CHECK1);
					pCheck->SetCheck(FALSE);
					spElement = pElement;
					//MessageBox(L"javascript:next('2');");
					break;
				}
			}// if(pElement.p != NULL)
		}// if(SUCCEEDED(hr))
	}

	if (spElement)
	{
		spElement->click();
	}
	else
	{
		return;
	}

	keybd_event(VK_RETURN, 0, 0, 0);
	keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
	
	CComPtr<IHTMLElement> pusername;
	spDocument->getElementById(L"username", &pusername);
	if (pusername != NULL)
	{
		CString username;
		GetDlgItemText(IDC_EDIT3, username);
		BSTR myinputbstr{username.AllocSysString()};
		spInputElement = pusername;
		spInputElement->put_value(myinputbstr);
		SysFreeString(myinputbstr);
	}

	CComPtr<IHTMLElement> pidentityCode;
	spDocument->getElementById(L"identityCode", &pidentityCode);
	if (pidentityCode != NULL)
	{
		CString identityCode;
		GetDlgItemText(IDC_EDIT4, identityCode);
		BSTR myinputbstr{ identityCode.AllocSysString() };
		spInputElement = pidentityCode;
		spInputElement->put_value(myinputbstr);
		SysFreeString(myinputbstr);
	}

	CString code;
	CComPtr<IHTMLElement> pimgRand;
	spDocument->getElementById(L"imgRand", &pimgRand);
	if (pimgRand != NULL)
	{
		CComQIPtr<IHTMLImgElement> pimg = pimgRand;
		VARIANT var;
		pimgRand->getAttribute(L"src", 0, &var);
		CString imgsrc = var;
		code = imgsrc.Mid(imgsrc.Find('=') + 1);
	}

	CComPtr<IHTMLElement> pverifyCode;
	spDocument->getElementById(L"verifyCode", &pverifyCode);
	if (pverifyCode != NULL)
	{
		CString verifyCode;
		BSTR myinputbstr{ code.AllocSysString() };
		spInputElement = pverifyCode;
		spInputElement->put_value(myinputbstr);
		SysFreeString(myinputbstr);
	}

	CComPtr<IHTMLElement> pmobile;
	spDocument->getElementById(L"mobile", &pmobile);
	if (pmobile != NULL)
	{
		CString mobile;
		GetDlgItemText(IDC_EDIT5, mobile);
		BSTR myinputbstr{ mobile.AllocSysString() };
		spInputElement = pmobile;
		spInputElement->put_value(myinputbstr);
		SysFreeString(myinputbstr);
	}

	spDocument->getElementsByTagName(L"a", &spCol);
	CComPtr<IHTMLElement> pSendCode;
	spCol->get_length(&count);
	for (int i = 0; i < count; i++)
	{
		CComVariant varName(i);
		varName.ChangeType(VT_UINT);
		CComVariant varIndex;
		CComPtr<IDispatch>pDisp;

		hr = spCol->item(varName, varIndex, &pDisp);
		if (SUCCEEDED(hr))
		{
			//CComQIPtr<IHTMLElement, &IID_IHTMLElement>pElement(pDisp);
			CComQIPtr<IHTMLAnchorElement, &IID_IHTMLAnchorElement>pElement(pDisp);

			if (pElement.p != NULL)
			{
				CComBSTR bstrHref;

				hr = pElement->get_href(&bstrHref);

				//pElement->get_tagName(&bstrHref);
				CString href{ bstrHref };
				if (href == "javascript:checkCode();")
				{
					pSendCode = pElement;
					break;
				}
			}// if(pElement.p != NULL)
		}// if(SUCCEEDED(hr))
	}
	if (pSendCode)
	{
		pSendCode->click();
	}

	spDocument->getElementsByTagName(L"input", &spCol);
	CComPtr<IHTMLElement> pCheck;
	spCol->get_length(&count);
	for (int i = 0; i < count; i++)
	{
		CComVariant varName(i);
		varName.ChangeType(VT_UINT);
		CComVariant varIndex;
		CComPtr<IDispatch>pDisp;

		hr = spCol->item(varName, varIndex, &pDisp);
		if (SUCCEEDED(hr))
		{
			CComQIPtr<IHTMLElement, &IID_IHTMLElement>pElement(pDisp);
			//CComQIPtr<IHTMLAnchorElement, &IID_IHTMLAnchorElement>pElement(pDisp);

			if (pElement.p != NULL)
			{
				VARIANT var;
				pElement->getAttribute(L"type", 0, &var);
				CString type{ var };
				if (type == "checkbox")
				{
					pCheck = pElement;
					break;
				}
			}// if(pElement.p != NULL)
		}// if(SUCCEEDED(hr))
	}
	if (pCheck)
	{
		//pCheck->put_checked(VARIANT_TRUE);
		pCheck->click();
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CMFCSportDlg::OnOK()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
}


void CMFCSportDlg::OnCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnCancel();
}


void CMFCSportDlg::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CDialogEx::OnCancel();
	CDialogEx::OnClose();
}
