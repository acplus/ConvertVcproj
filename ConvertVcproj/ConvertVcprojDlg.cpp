
// ConvertVcprojDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ConvertVcproj.h"
#include "ConvertVcprojDlg.h"
#include "ParseVcxproj.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CConvertVcprojDlg �Ի���




CConvertVcprojDlg::CConvertVcprojDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CConvertVcprojDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CConvertVcprojDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CConvertVcprojDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON_CONVERT, &CConvertVcprojDlg::OnBnClickedButtonConvert)
END_MESSAGE_MAP()


// CConvertVcprojDlg ��Ϣ�������

BOOL CConvertVcprojDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	SetDlgItemText(IDC_EDIT_VCXPROJ, theApp.m_StrVcxprojPath);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CConvertVcprojDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CConvertVcprojDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CConvertVcprojDlg::OnOK()
{
	//CDialog::OnOK();
}

void CConvertVcprojDlg::OnCancel()
{
	//CDialog::OnCancel();
}

void CConvertVcprojDlg::OnClose()
{
	CDialog::OnCancel();
}

void CConvertVcprojDlg::OnBnClickedButtonConvert()
{
	//CFileDialog fileDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
	//	_T("vcxproj�ļ�(*.vcxproj)|*.vcxproj|�����ļ�(*.*)|*.*||"));
	//if (fileDlg.DoModal() == IDOK)
	//{

	//}
	CString strPath;
	GetDlgItemText(IDC_EDIT_VCXPROJ, strPath);
	theApp.m_StrVcxprojPath = strPath;
	CParseVcxproj parse;
	CFile file;
	if (file.Open(strPath, CFile::modeRead))
	{
		unsigned int uSize = (unsigned int)file.GetLength();
		char *pBuffer = new char[uSize + 2];
		ZeroMemory(pBuffer, uSize + 2);
#if _MSC_VER >= 1300
		file.Read ((void*)pBuffer, uSize);
#else
		file.ReadHuge ((void*)pBuffer, uSize);
#endif
		parse.Parse(pBuffer);
		delete[] pBuffer;
		file.Close();
	}
	strPath.Append(_T(".filters"));
	if (file.Open(strPath, CFile::modeRead))
	{
		unsigned int uSize = (unsigned int)file.GetLength();
		char *pBuffer = new char[uSize + 2];
		ZeroMemory(pBuffer, uSize + 2);
#if _MSC_VER >= 1300
		file.Read ((void*)pBuffer, uSize);
#else
		file.ReadHuge ((void*)pBuffer, uSize);
#endif
		parse.ParseFilters(pBuffer);
		delete[] pBuffer;
		file.Close();
	}
}
