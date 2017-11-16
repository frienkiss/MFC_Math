
// MathDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Math.h"
#include "MathDlg.h"
#include "afxdialogex.h"

#include "Ex_Grade.h"

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


// CMathDlg �Ի���



CMathDlg::CMathDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMathDlg::IDD, pParent)
	, m_name(_T(""))
	, m_Minute(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMathDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDX_Text(pDX, IDC_TIME, m_Minute);
}

BEGIN_MESSAGE_MAP(CMathDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BEGIN, &CMathDlg::OnClickedBegin)
	//ON_BN_CLICKED(IDC_CHECK3, &CMathDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_BUTTON2, &CMathDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMathDlg ��Ϣ�������

BOOL CMathDlg::OnInitDialog()
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
	//m_font.SetFont();//���ø�ѡ�����ִ�С


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMathDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMathDlg::OnPaint()
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
HCURSOR CMathDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMathDlg::OnClickedBegin()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//CEx_Dlg* pdlg;
	


	//CString strCtrl;
	UpdateData(true);
	if (m_name.GetLength()==0){
		MessageBox(L"����д��ϰ��������");
		return;
	}
	else{
		CString str, strj, strCtrl;
		int m = rand() % 100 + 1;
		//int o = 1;
		int j = rand() % 100 + 1;
		//Sub = m + j;


		UINT nCheckIDs[3] = { IDC_CHECK1, IDC_CHECK2, IDC_CHECK3 };//���δѡ���������Ҫ��������    �ڶ��ο�ʼʱ��ѡҲ�ܽ���
		CButton* pBtn;
		int r = 0;
		for (int i = 0; i < 3; i++)
		{
			pBtn = (CButton*)GetDlgItem(nCheckIDs[i]);
			if (pBtn->GetCheck())
			{
				
				pBtn->GetWindowText(strCtrl);
				//�������ùܸ���������
				dlg1.strop[r] = strCtrl;//��¼�����
				r++;
				dlg1.count++;
			}
		}
		if (dlg1.count == 0){
			MessageBox(L"��ѡ���������");
			return;
		}
		//MessageBox(str);

		//switch ()
		int k = rand() % dlg1.count;//����0~count-1�������������ѡ�������
		//MessageBox(dlg1.strop[k]);//�ڶ��β���Ϊ��

		if (dlg1.strop[k] == "+"){
			r = 0;
			//dlg1.strop[k] = "+";
		}
		if (dlg1.strop[k] == "-")
		{

			r = 1;
			//dlg1.strop[k] = "-";
		}
		if (dlg1.strop[k] == "*"){
			r = 2;//
			//dlg1.strop[k] = "*";
		}
		switch (r){
		case 0:
			dlg1.result = m + j; break;
		case 1:{//"����  ����const char ����ת����Cstring
				   if (m < j){
					   int temp;
					   temp = m; m = j; j = temp;
				   }

				   dlg1.result = m - j; break;
		}
		case 2:		dlg1.result = m*j; break;

		}
		str.Format(L"%d", m);
		strj.Format(L"%d", j);
		str = str + dlg1.strop[k] + strj;
		dlg1.m_val = str;//�ȸ���ֵ���ٹ���Ի���
		strj.Format(L"=%d", dlg1.result);
		str = str + strj;
		UpdateData(true);
		dlg1.m_minute = m_Minute;//��ϰʱ�䣺����
		dlg1.count1 = 0;
		dlg1.grade[dlg1.count1] = str;
		dlg1.count1++;
		dlg1.t_name[dlg1.count2] = m_name;
		//MessageBox(dlg1.t_name[dlg1.count2]);
		//dlg1.GetDlgItem(IDC_EDIT5)->EnableWindow(FALSE);
		//dlg1.Timer();
		//dlg1.SetTimer(1, 1000, NULL);
		dlg1.m_sec = 0;//����������
		dlg1.DoModal();
		//MessageBox(L"fjdskfsdjk");
		UpdateData(true);
		m_name ="";
		m_Minute = 0;
		//CButton* pBtn;
		CheckDlgButton(IDC_CHECK1, 0);
		CheckDlgButton(IDC_CHECK2, 0);
		CheckDlgButton(IDC_CHECK3, 0);
		/*for (int i = 0; i < 3; i++)
		{
			pBtn = (CButton*)GetDlgItem(nCheckIDs[i]);
			pBtn->SetState(0);
		}//��ѡ��ȡ��ѡ��*/
		UpdateData(false);
		

		//dlg1.SetTimer(1, 1000, NULL);
		//pdlg->Timer();
		//UpdateData(true);

		/*dlg1.UpdateData(true);
		if (dlg1.m_Sub == dlg1.Sub)
		dlg1.m_score++;*/



		/*dlg1.UpdateData(true);
		dlg1.m_val = str;
		dlg1.UpdateData(false);*/
	}
	
}





void CMathDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	Ex_Grade gravalue;//�Ի�������MultiLine��Ϊtrue
	UpdateData(true);
	gravalue.m_grade = dlg1.t_name[dlg1.count2-1] + L"\r\n";
	gravalue.m_grade = gravalue.m_grade + L"   ��Ŀ           ��Ĵ�       ���� \r\n";
	//strctrl = m_name+L"\r";
	//strctrl = strctrl+L"��Ŀ                  ��Ĵ�\r";  
	for (int i = 0; i < dlg1.count1-1; i++)
	{
		
			if (i %2==1)
				gravalue.m_grade = gravalue.m_grade + dlg1.grade[i] + L"\r\n";
			else
				gravalue.m_grade = gravalue.m_grade + dlg1.grade[i]+L"        ";
		
		//strctrl= strctrl+dlg1.grade[i]+L"\r";//��һ����û��¼
	}
	//MessageBox(strctrl);
	//gravalue.m_grade = strctrl;
	gravalue.DoModal();


}
