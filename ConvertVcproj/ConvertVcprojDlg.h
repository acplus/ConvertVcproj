
// ConvertVcprojDlg.h : ͷ�ļ�
//

#pragma once


// CConvertVcprojDlg �Ի���
class CConvertVcprojDlg : public CDialog
{
// ����
public:
	CConvertVcprojDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CONVERTVCPROJ_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	virtual void OnOK();
	virtual void OnCancel();
public:
	afx_msg void OnClose();
	afx_msg void OnBnClickedButtonConvert();
};
