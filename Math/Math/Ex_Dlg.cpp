// Ex_Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Math.h"
#include "Ex_Dlg.h"
#include "Ex_Grade.h"
#include "afxdialogex.h"
//#include "MathDlg.h"


// CEx_Dlg 对话框

IMPLEMENT_DYNAMIC(CEx_Dlg, CDialogEx)

CEx_Dlg::CEx_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CEx_Dlg::IDD, pParent)
	, m_val(_T(""))
	, m_score(NULL)//null预定义是0
	, m_sec(0)
	, m_minute(0)
	, m_Sub(_T(""))
{

	EnableAutomation();
	//SetTimer(1, 1000, NULL);
	//SetDlgItemText(IDC_EDIT5, L" ");
	//UpdateData(false);//最初
	//Timer();

}

CEx_Dlg::~CEx_Dlg()
{
}

void CEx_Dlg::OnFinalRelease()
{
	// 释放了对自动化对象的最后一个引用后，将调用
	// OnFinalRelease。  基类将自动
	// 删除该对象。  在调用该基类之前，请添加您的
	// 对象所需的附加清理代码。

	CDialogEx::OnFinalRelease();
}

void CEx_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT4, m_val);
	//DDX_Text(pDX, IDC_EDIT5, m_Sub);
	DDX_Text(pDX, IDC_EDIT2, m_score);
	DDX_Control(pDX, IDC_EDIT5, M_SUB);
	DDX_Text(pDX, IDC_EDIT1, m_sec);
	DDV_MinMaxInt(pDX, m_sec, -1, 59);
	DDX_Text(pDX, IDC_EDIT3, m_minute);
	//Timer();
	DDX_Text(pDX, IDC_EDIT5, m_Sub);
}


BEGIN_MESSAGE_MAP(CEx_Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CEx_Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CEx_Dlg::OnBnClickedButton2)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON3, &CEx_Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CEx_Dlg, CDialogEx)
END_DISPATCH_MAP()

// 注意: 我们添加 IID_IEx_Dlg 支持
//  以支持来自 VBA 的类型安全绑定。  此 IID 必须同附加到 .IDL 文件中的
//  调度接口的 GUID 匹配。

// {F8F23BF7-9033-4ACF-8D63-F7EDE0A81516}
static const IID IID_IEx_Dlg =
{ 0xF8F23BF7, 0x9033, 0x4ACF, { 0x8D, 0x63, 0xF7, 0xED, 0xE0, 0xA8, 0x15, 0x16 } };

BEGIN_INTERFACE_MAP(CEx_Dlg, CDialogEx)
	INTERFACE_PART(CEx_Dlg, IID_IEx_Dlg, Dispatch)
END_INTERFACE_MAP()


// CEx_Dlg 消息处理程序

//开始练习
void CEx_Dlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	/*CString m3;
	m3.Format(L"%d", result);
	MessageBox(m3);//检验result是不是传递了正确的值*/
	//Timer();
	//SetTimer(1, 1000, NULL);
	Ex_Grade gravalue;//成绩
	CString pan;
	
	UpdateData(true);
	
	if (m_Sub ==""){
		MessageBox(L"结果不能为空！");
		return;
	}
	
		
		Checkequal(result, m_Sub);
		CString str, strk1, strk2;
		//strk1=L"=";//借用下变量记录=
		
		grade[count1] = m_val + +L"="+m_Sub;
		count1++;
		//m_Sub = NULL;
		//M_SUB.SetWindowTextW(L"FDS");
		//M_SUB = NULL;
		//SetDlgItemTextW(IDC_EDIT5, NULL);//刷新编辑框为空白，以便填写内容
		
		
		
	
		UpdateData(false);

		//M_SUB.SetSel(0, -1);
		//M_SUB.ReplaceSel(L" ");
		int k1 = rand() % 100 + 1;
		int k2 = rand() % 100 + 1;
		
		//result = k1 + k2;



		int r;//在一次运行上操作两次会出错，r？？第二次没有记录运算符吗




		int k = rand() % count;//产生0~count-1的数，用来随机选择运算符
		
		if (strop[k] == "+"){
			r = 0;
		//	strop[k] = "+";//下一次进入时strop[k]值为"+",这个判断语句就失效了
		}
		if (strop[k] == "-"){
			r = 1;
			//strop[k] = "-";
		}
		if (strop[k] == "*"){
			r = 2;//
			//strop[k] = "*";
		}
		switch (r){
		case 0:
			result = k1 + k2; break;
		case 1:{
				   if (k1 < k2){
					   int temp;
					   temp = k1; k1 = k2; k2 = temp;
				   }
				   result = k1 - k2; break;

		}//保证小学生就算不出现负数
			
		case 2:
			result = k1*k2; break;

		}
	
		strk1.Format(L"%d", k1);
		strk2.Format(L"%d", k2);
		str = strk1 + strop[k] + strk2;
		UpdateData(true);
		m_val = str;


		strk1.Format(L"%d", result);
		strk2 = "=";
		grade[count1] = str + strk2 + strk1;
		
		count1++;
		if (count1 > 20){
			MessageBox(L"题数已经达到上限，请结束并重新答题！");
			OnCancel();
		}
		//strk2.Format(L"%d", m_score);//得分，判断result和m_Sub

		/*CString m1, m2;
		m1.Format(L"%d", Sub);
		m2.Format(L"%d", m_Sub);
		MessageBox(m1);//Sub为xia一个计算式的值
		MessageBox(m2);*/



		//m_score++;
		//InvalidateRect();
	
		
		UpdateData(FALSE);
		SetDlgItemText(IDC_EDIT5, L" ");
		

		
	
		
	
	

	

	/*UpdateData(true);
	m_val = str;
	UpdateData(false);*/


}


//计分
void CEx_Dlg::Checkequal(int sub,CString m_sub)
{
	int m;
	m = _ttoi(m_sub);//Cstring->int
	if (sub == m)
		m_score++;

}


/*void CEx_Dlg::Timer()
{
	UpdateData(true);

	while (m_minute != -1)
	{
		m_sec--;
		if (m_minute == 0 && m_sec == 0){
			MessageBox(L"练习时间结束！");
			OnCancel();

		}
		if (m_sec = -1){
			m_sec = 59;

			m_minute--;
		}
		UpdateData(false);
	}
	Timer();

	//return 0;
}*/

//结束练习
void CEx_Dlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	/*if (::MessageBox(m_hWnd, _T("练习时间未结束，你确认要结束答题吗？"), _T("信息提示"), MB_OKCANCEL) == IDCANCEL)
		return;*/
	//CString str;
	//str.Format(L"最高分为 %d", m_score);
	if (m_minute != 0 || m_sec != 0)
	{
		if (::MessageBox(m_hWnd, _T("练习时间未结束，你确认要结束答题吗？"), _T("信息提示"), MB_OKCANCEL) == IDCANCEL)


			
			return;
		
		//OnDestroy();
		//this->OnDestroy();
		CDialog::OnOK();//
		UpdateData(true);
		m_Sub = L"";
		m_Score[count2] = m_score;
		Highest = m_Score[count2];
		sign = count2;
		count2++;//结束一次练习代表练习者人数加1
		
		for (int i = count2-1; i >= 0; i--)
		{
			if (m_Score[i]>Highest)
			{
				Highest = m_Score[i];
				sign = i;
			}
			
		}
		//m_sec = 0;//不在这里重置，否则会影响定时器，重置为0，假如miniute为0，会弹出练习时间结束，实际未结束，是强行结束练习
		m_score = 0;
		count = 0;//重新练习，运算符个数置为0初始
		//count1 = 0;//重新记录另一个练习者的练习数目,不能在这里重置，会影响练习记录
		UpdateData(false);
		CString strc;
		strc.Format(L"%d", Highest);
		strc = L"最高分为：" + strc+L"\r\n";
		strc = strc + L"练习者为：" + t_name[sign];
		MessageBox(strc);

		//for (int i = 0; i < count; i++)
			//strop[i].Empty();
		//MessageBox(str);
	}

}

//计时
void CEx_Dlg::OnTimer(UINT_PTR nIDEvent)//要考虑下时间停止时正好按下结束练习，值变化的问题

{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	UpdateData(true);

	
	if (m_minute > 0){//中断异常？
		if (m_sec > 0)
			m_sec--;
		else
		{
			m_minute--;
			m_sec = 59;
		}
	}
	else{
		if (m_sec > 0)
			m_sec--;
		else
		{
			KillTimer(nIDEvent);
				MessageBox(L"练习时间结束！");//自动结束时间和强制结束时间后的操作应该是一致的
				CDialog::OnOK();
				UpdateData(true);
				m_Sub = L"";
				m_Score[count2] = m_score;
				Highest = m_Score[count2];
				sign = count2;
				count2++;//结束一次练习代表练习者人数加1

				for (int i = count2-1; i >= 0; i--)
				{
					if (m_Score[i]>Highest)
					{
						Highest = m_Score[i];
					sign = i;//借用count记录最高分在m_Score数组中的位置，m_Score[]和t_name[]数组中姓名分数是一一对应的
						
					}

				}
				//m_sec = 0;//不在这里重置，否则会影响定时器，重置为0，假如miniute为0，会弹出练习时间结束，实际未结束，是强行结束练习
				m_score = 0;
				count = 0;//重新练习，运算符个数置为0初始
				//count1 = 0;//重新记录另一个练习者的练习数目,不能在这里重置，会影响练习记录
				UpdateData(false);
				CString strc;
				strc.Format(L"%d", Highest);
				strc = L"最高分为：" + strc + L"\r\n";
				strc = strc + L"练习者为：" + t_name[sign];
				MessageBox(strc);
				
				//OnCancel();
			
			
		}
	}
		/*if (m_sec>=0)
		 m_sec--;
		if (m_minute==0&&m_sec == 0)
		{
			MessageBox(L"练习时间结束！");
			OnCancel();
		}
		if (m_sec = 0){
			m_sec = 59;

			m_minute--;
		}*/
		UpdateData(false);
	 //do while

		//MessageBox(L"练习时间结束！");
		//OnCancel();

	
	CDialogEx::OnTimer(nIDEvent);
}


void CEx_Dlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代码
	SetTimer(1, 1000, NULL);
	//GetDlgItem(IDC_EDIT5)->EnableWindow(TRUE);//点击开始计时后编辑框才允许输入内容
}
