#include <fstream>
#include <iostream>
#include <string>
using namespace std;
//#define BASIC
#define DEMO1
//#define DEMO2
//#define DEMO3
//#define DEMO4

#ifdef DEMO1
void file_wr(void)
{
    char data[100];
    ofstream outfile;
    outfile.open("test.txt");
    cout << "Write to the file" << endl;
    cout << "Enter your name:" << endl;
    cin.getline(data, 100);
    outfile << data << endl;
    cout << "Enter your age:" << endl;
    cin >> data;
    cin.ignore();
    outfile << data << endl;
    outfile.close();

    ifstream infile;
    infile.open("test.txt");
    cout << "Read from the file" << endl;
    infile >> data;
    cout << data << endl;
    infile >> data;
    cout << data << endl;
    infile.close();
}

void file_copy(void)
{
    char data[100];
    ifstream infile;
    ofstream outfile;

    infile.open("test.txt");
    outfile.open("test_1.txt");
    cout << "copy from test.txt to test_1.txt" << endl;
    //while (!infile.eof()) {
    //调用eof函数文件的最后一行会被复制两遍。
    while (infile >> data) {
        infile >> data;
        cout << data << endl;
        outfile << data << endl;
    }
    infile.close();
    outfile.close();
}
#endif

#ifdef DEMO4
int WriteFile(string filepath, const string& Init)
{
    ofstream outfile;

    outfile.open(filepath, ios::out | ios::trunc);
    if(!outfile)
        return 1;
    outfile << Init << endl;
    
    outfile.close();
    return 0;
}

string Read_Str(string filepath)
{
    ifstream infile;
    infile.open(filepath);
    if(!infile)
        cout << "Open File Fail!" << endl;
    string readStr((std::istreambuf_iterator<char>(infile)), std::istreambuf_iterator<char>());

    return readStr;
}
#endif

int main()
{
#ifdef DEMO4
    WriteFile("Demo4.txt", "Hello, world!");
    cout << Read_Str("Demo4.txt") << endl;
#endif
#ifdef BASIC
    char data[100];

    //以写模式打开文件
    ofstream outfile;
    outfile.open("afile.dat");


    cout << "Writing to the file." << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);

    //向文件中写入输入的数据
    outfile << data << endl;

    cout << "Enter yout age: ";
    cin >> data;    
    cin.ignore();

    outfile << data << endl;
    outfile.close();
    
    ifstream infile;
    infile.open("afile.dat");
    infile >> data;
    cout << data << endl;
    infile >> data;
    cout << data << endl;

    infile.close();
#endif

#ifdef DEMO1
    file_wr();
    file_copy();
    return 0;
#endif

#ifdef DEMO2
    //ignore 用来消除缓冲区的影响
    int a,b,c;
    cout << "input a:";
    cin >> a;
    cin.ignore(1024, '\n');
    cout << "input b:";
    cin >> b;
    cin.ignore(1024, '\n');
    cout << "input c:";
    cin >> c;
    cout << a << "\t" << b << "\t" << c <<endl;

    //cin.ignore如果不给参数，EOF则在文字流的结尾。
    char str1[30], str2[30], str3[30];
    cout << "Enter your name:";
    cin >> str1;
    cout << "Enter your address:";
    cin.ignore();
    cin.getline(str2, 30, 'a');
    cout << "pls input your nation:";
    cin.ignore();
    cin.getline(str3, 30);
    cout << str3;
#endif

#ifdef DEMO3
    //用fstream来定义文件流
    fstream iofile;
    iofile.open("Demo3.txt", ios::out | ios::in | ios::trunc);
    string bookname;
    string bookwriter;
    cout << "input the bookname:"  << endl;
    getline(cin, bookname);
    iofile << bookname << endl;
    cout << "input the bookwriter:" << endl;
    getline(cin, bookwriter);
    iofile << bookwriter << endl;
    iofile.close();
    cout << "read and input file:" << endl;
    iofile.open("Demo3.txt");
    while(getline(iofile, bookname))
    {
        cout << bookname << endl;
    }
#endif

    return 0;
}
