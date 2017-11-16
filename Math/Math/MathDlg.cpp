
// MathDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Math.h"
#include "MathDlg.h"
#include "afxdialogex.h"

#include "Ex_Grade.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CMathDlg 对话框



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


// CMathDlg 消息处理程序

BOOL CMathDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	//m_font.SetFont();//设置复选框文字大小


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMathDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMathDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMathDlg::OnClickedBegin()
{
	// TODO:  在此添加控件通知处理程序代码
	//CEx_Dlg* pdlg;
	


	//CString strCtrl;
	UpdateData(true);
	if (m_name.GetLength()==0){
		MessageBox(L"请填写练习者姓名！");
		return;
	}
	else{
		CString str, strj, strCtrl;
		int m = rand() % 100 + 1;
		//int o = 1;
		int j = rand() % 100 + 1;
		//Sub = m + j;


		UINT nCheckIDs[3] = { IDC_CHECK1, IDC_CHECK2, IDC_CHECK3 };//如果未选择运算符，要发出警告    第二次开始时不选也能进入
		CButton* pBtn;
		int r = 0;
		for (int i = 0; i < 3; i++)
		{
			pBtn = (CButton*)GetDlgItem(nCheckIDs[i]);
			if (pBtn->GetCheck())
			{
				
				pBtn->GetWindowText(strCtrl);
				//减法不用管负数。。。
				dlg1.strop[r] = strCtrl;//记录运算符
				r++;
				dlg1.count++;
			}
		}
		if (dlg1.count == 0){
			MessageBox(L"请选择运算符！");
			return;
		}
		//MessageBox(str);

		//switch ()
		int k = rand() % dlg1.count;//产生0~count-1的数，用来随机选择运算符
		//MessageBox(dlg1.strop[k]);//第二次操作为空

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
		case 1:{//"减“  错误const char 不能转换成Cstring
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
		dlg1.m_val = str;//先给初值，再构造对话框
		strj.Format(L"=%d", dlg1.result);
		str = str + strj;
		UpdateData(true);
		dlg1.m_minute = m_Minute;//练习时间：分钟
		dlg1.count1 = 0;
		dlg1.grade[dlg1.count1] = str;
		dlg1.count1++;
		dlg1.t_name[dlg1.count2] = m_name;
		//MessageBox(dlg1.t_name[dlg1.count2]);
		//dlg1.GetDlgItem(IDC_EDIT5)->EnableWindow(FALSE);
		//dlg1.Timer();
		//dlg1.SetTimer(1, 1000, NULL);
		dlg1.m_sec = 0;//在这里重置
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
		}//复选框取消选择*/
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
	// TODO:  在此添加控件通知处理程序代码
	Ex_Grade gravalue;//对话框属性MultiLine设为true
	UpdateData(true);
	gravalue.m_grade = dlg1.t_name[dlg1.count2-1] + L"\r\n";
	gravalue.m_grade = gravalue.m_grade + L"   题目           你的答案       正误 \r\n";
	//strctrl = m_name+L"\r";
	//strctrl = strctrl+L"题目                  你的答案\r";  
	for (int i = 0; i < dlg1.count1-1; i++)
	{
		
			if (i %2==1)
				gravalue.m_grade = gravalue.m_grade + dlg1.grade[i] + L"\r\n";
			else
				gravalue.m_grade = gravalue.m_grade + dlg1.grade[i]+L"        ";
		
		//strctrl= strctrl+dlg1.grade[i]+L"\r";//第一道题没记录
	}
	//MessageBox(strctrl);
	//gravalue.m_grade = strctrl;
	gravalue.DoModal();


}
