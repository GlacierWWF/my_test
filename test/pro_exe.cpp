#include <iostream>
#include<vector>
using namespace std;
string longestCommon(vector<string>& strs);
int main ()
{
    vector<string> str;     //将要处理的字符串
    string temp;        //暂时存储输入字符串
    cout<<"请输入任意字符串（如果输入完毕，请输入:q）："<<endl;
    cin>>temp;
    while(temp!=":q")       //当输入:q时，不再接受字符串
    {
        str.push_back(temp);
        cin>>temp;
    }
    string res;     //最终结果放置的地方
    res=longestCommon(str);
    if(res=="")     //判断后缀是否为空
    {
        cout<<"最大相同后缀为空"<<endl;
    }
    else
    {
        cout<<"最大相同后缀为： "<<res<<endl;
    }

   return 0;
}

string longestCommon(vector<string>& strs) {
    int i, j, check;
    string temp1,temp2;     //暂时存储字符串
    string res0="";     //结果存储的位置
    temp1=strs[0];
    for(i=temp1.length()-1;i>-1;i--)
    {
        for(j=1;j<strs.size();j++)
        {
            temp2=strs[j];
            if(temp1[i]==temp2[temp2.length()-1])       //用来判断最后一个字母是否相同
            {
                check=1;
                (strs[j]).pop_back();       //如果最后一个字母相同，就压出最后一个字母
            }
            else
            {
                check=0;
                break;
            }
        }
        if(check==1)
        {
            res0=res0+temp1[i];
        }
        else
        {
            break;
        }
    }
    string res_temp=res0;       //将获得的字符串反向
    for(i=0;i<res0.length();i++)
    {
        res0[i]=res_temp[res0.length()-i-1];
    }
    return  res0;
}

