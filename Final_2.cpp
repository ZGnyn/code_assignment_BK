#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;

struct SinhVien {
    int stt; 
    char HoVaTen[50];
    char GioiTinh[50];
    char MSSV[50];
    char Lop[50];
    double GPA;
};

// Hàm nhập thông tin SV
void NhapSinhVien(SinhVien &sv, int stt) {
    sv.stt = stt;
    cout << "STT: " << stt;
    cout << "\n Nhap Ho va ten: "; fflush(stdin); gets(sv.HoVaTen);
    cout << " Nhap Gioi tinh: "; gets(sv.GioiTinh);
    cout << " Nhap MSSV: "; gets(sv.MSSV);
    cout << " Nhap Lop: "; fflush(stdin); gets(sv.Lop);
    cout << " Nhap GPA: "; cin >> sv.GPA;
}

// Hàm nhập SV vào mảng DanhSach[]
void NhapDanhSach(SinhVien DanhSach[100], int TongSinhVien, int stt) {
    NhapSinhVien(DanhSach[TongSinhVien],stt);
}

// Hàm xuất mảng DanhSach[]
void XuatDanhSach(SinhVien DanhSach[100], int TongSinhVien) {

    cout<<setfill('+');
    cout<<setw(35)<<"+"<< " DANH SACH SINH VIEN ";
    cout<<setfill('+');
    cout<<setw(35)<<"+"<<endl;
    cout<<setfill(' ');
    cout<<setw(10)<<left<<"\nSTT";
    cout<<setw(30)<<left<<" Ho va ten";
    cout<<setw(15)<<left<<" Gioi tinh ";
    cout<<setw(15)<<left<<" MSSV ";
    cout<<setw(15)<<left<<" Lop ";
    cout<<setw(20)<<" GPA " << endl;
    cout<<setfill('-');
    cout<<setw(90)<<"-"<<endl;
    cout<<setfill(' ');

    for (int i = 1; i <= TongSinhVien; i++) {
        cout <<setw(10)<<left<< DanhSach[i].stt;
        cout <<setw(30)<<left<< DanhSach[i].HoVaTen ;
        cout <<setw(15)<<left<< DanhSach[i].GioiTinh;
        cout <<setw(15)<<left<< DanhSach[i].MSSV ;
        cout <<setw(15)<<left<< DanhSach[i].Lop;
        cout <<setw(20)<< DanhSach[i].GPA;
        cout << endl;
    }
}

// Hàm xóa SV theo STT trong DanhSach[]
bool XoaSinhVien(SinhVien DanhSach[100], int TongSinhVien) {
    int stt_xoa; // Khai báo STT muốn xoas
    bool exist; // Khai báo biến exist để kiểm tra SV có tồn tại hay không 

    cout << "Nhap STT cua Sinh vien bi xoa: "; cin >> stt_xoa;

    // Nếu SV tồn tại
    for (int i = 1; i <= TongSinhVien; i++) {
        if (DanhSach[i].stt == stt_xoa) {
            exist = true;
            // Xóa thông tin của Sinh viên 
            for (int j = i; j <= TongSinhVien; j++) {
                DanhSach[j] = DanhSach[j + 1];
            }
            // Xóa số thứ tự của sinh viên
            DanhSach[TongSinhVien - 1].stt-- ;  
            cout << "Da xoa sinh vien co STT la: " << stt_xoa << endl;
            return true;
        }
    }

    // Nếu SV không tồn tại
    if (!exist) {
        cout << "KHONG TON TAI sinh vien co STT la: " << stt_xoa << endl;
        return false;
    }
    
}

// Hàm chỉnh sửa SV theo STT trong DanhSach[]
void CapNhatSinhVien(SinhVien DanhSach[100], int TongSinhVien) {
    int stt_sua; // Khai báo STT muốn sửa
    bool exist; // Khai báo biến exist để kiểm tra SV có tồn tại hay không 

    cout << "Nhap STT cua sinh vien: "; cin >> stt_sua;

    // Nếu SV tồn tại
    for (int i = 1; i <= TongSinhVien ; i++ ) {
        if (DanhSach[i].stt == stt_sua){
            exist = true; 
            NhapSinhVien(DanhSach[i],stt_sua);
            cout << "Da cap nhat thong tin sinh vien co ID = " << stt_sua <<endl;
            break;
        }
    }

    // Nếu SV không tồn tại
    if (!exist) {
        cout << "KHONG TON TAI sinh vien co STT la: " << stt_sua << endl;
    }
}

// Hàm tìm sinh viên theo Lớp
void TimTheoLop(SinhVien DanhSach[100], int TongSinhVien) {
    string lop_can_tim;  // Khai báo Lớp muốn tìm
    bool exist;  // Khai báo biến exist để kiểm tra Lớp có tồn tại hay không 

    cout<<"Nhap Lop muon tim: "; cin>>lop_can_tim;
    
    cout<<setw(10)<<left<<"\nSTT";
    cout<<setw(30)<<left<<" Ho va ten";
    cout<<setw(15)<<left<<" Gioi tinh ";
    cout<<setw(20)<<left<<" MSSV " << endl;
    cout<<setfill('-');
    cout<<setw(62)<<"-"<<endl;
    cout<<setfill(' ')<<endl;

    // Nếu Lớp tồn tại
    for (int i = 1; i <= TongSinhVien; i++) {
        if ( lop_can_tim == DanhSach[i].Lop) {
            exist = true;
            cout <<setw(10)<<left<< DanhSach[i].stt ;
            cout <<setw(30)<<left<< DanhSach[i].HoVaTen ;
            cout <<setw(15)<<left<< DanhSach[i].GioiTinh;
            cout <<setw(20)<<left<< DanhSach[i].MSSV <<"\n";  
      }
    }
    
    // Nếu Lớp không tồn tại
    if(!exist) {
        cout<<"KHONG ton tai lop nay\n";
    }
}

// Hàm sắp xếp sinh viên theo GPA giảm dần
void GPAgiam(SinhVien DanhSach[], int TongSinhVien)
{
    SinhVien temp;
    for (int i = 1; i <= TongSinhVien; i++)
    {
        for (int j = i; j <= TongSinhVien; j++)
        {
            if (DanhSach[i].GPA < DanhSach[j].GPA)
            {
                temp = DanhSach[i];
                DanhSach[i] = DanhSach[j];
                DanhSach[j] = temp;
            }
        }
    }
}

void STTtang(SinhVien DanhSach[], int TongSinhVien)
{
    SinhVien temp;
    for (int i = 1; i <= TongSinhVien; i++)
    {
        for (int j = i; j <= TongSinhVien; j++)
        {
            if (DanhSach[i].stt > DanhSach[j].stt)
            {
                temp = DanhSach[i];
                DanhSach[i] = DanhSach[j];
                DanhSach[j] = temp;
            }
        }
    }
}

int main() {
    SinhVien DanhSach[100]; // Khai báo Mảng DanhSach[] chứa SV
    int TongSinhVien = 0; // Biến đếm số lượng Sinh viên trong DanhSach[]
    int stt = 0; // Biến STT của 1 SV 
    int option; // Biến chọn MENU

    // MENU 
    while (true) {
        cout << endl << "CHUONG TRINH QUAN LY SINH VIEN C++" << endl << endl;
        cout << "*************************MENU**************************" << endl;
        cout << "*** 1. Nhap danh sach sinh vien                     ***" << endl;
        cout << "*** 2. Xuat danh sach sinh vien                     ***" << endl;
        cout << "*** 3. Xoa sinh vien theo STT                       ***" << endl;
        cout << "*** 4. Cap nhat thong tin sinh vien theo STT        ***" << endl;
        cout << "*** 5. Tim sinh vien theo Lop                       ***" << endl;
        cout << "*** 6. Sap xep sinh vien theo GPA giam dan          ***" << endl;
        cout << "*** 0. Thoat chuong trinh                           ***" << endl;
        cout << "*******************************************************" << endl;
        cout << "Nhap tuy chon cua ban: "; cin >> option; 

        switch (option) {
            case 1:
                cout << "\n++++++++++ NHAP DANH SACH ++++++++++" << endl;
                int n; 
                cout << "Ban muon them bao nhieu sinh vien: ";  cin >> n; 
                for (int i = 0; i < n; i++) {
                    stt++;
                    TongSinhVien++;
                    NhapDanhSach(DanhSach,TongSinhVien,stt);
                }
                break;

            case 2:
                XuatDanhSach(DanhSach,TongSinhVien);
                break;

            case 3:
                cout << "\n++++++++++ XOA SINH VIEN THEO ID ++++++++++" << endl;
                if (TongSinhVien > 0) {
                    int stt_xoa;
                    if (XoaSinhVien(DanhSach,TongSinhVien) == true ){
                        stt--;
                        TongSinhVien--;
                    }
                } else {
                    cout << "KHONG co sinh vien trong danh sach. Moi ban nhap lai";
                }
                break;

            case 4:
                cout << "\n++++++++++ CAP NHAT SINH VIEN THEO ID ++++++++++" << endl;
                if (TongSinhVien > 0) {
                    CapNhatSinhVien(DanhSach,TongSinhVien) ;
                } else {
                    cout << "KHONG co sinh vien trong danh sach. Moi ban nhap lai" ;
                }
                break;

            case 5:
                cout << "\n++++++++++ TIM SINH VIEN THEO LOP ++++++++++" << endl;
                if (TongSinhVien > 0) {
                    TimTheoLop(DanhSach,TongSinhVien);
                } else {
                    cout << "KHONG co sinh vien trong danh sach. Moi ban nhap lai";
                }
                break;

            case 6:
                cout <<"\n++++++++++ SAP XEP SINH VIEN THEO GPA ++++++++++" << endl;
                if (TongSinhVien > 0) {
                    GPAgiam(DanhSach,TongSinhVien);
                    XuatDanhSach(DanhSach,TongSinhVien);
                    STTtang(DanhSach,TongSinhVien);
                } else {
                    cout << "KHONG co sinh vien trong danh sach. Moi ban nhap lai";
                }
                break;
            case 0: 
                cout << "\nBan da chon thoat chuong trinh!";
                return 0;
            default:
                cout << "\nKhong co chuc nang nay!";
                cout << "\nHay chon chuc nang trong hop menu.";
                break;
        }
    }  
}
