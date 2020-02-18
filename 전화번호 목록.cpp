#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <unordered_map>



using namespace std;


bool solution(vector<string> phone_book) {
    bool answer = true;
    if( phone_book.size() < 1 || phone_book.size() > 1000000 ) return 0;
    for(auto iter = phone_book.begin(); iter!=phone_book.end(); iter++)
    {
        string abc = *iter;
        if( abc.length() < 1 || abc.length() > 20 ) return 0;
    }
    
    //Input값을 hash table로 저장
    unordered_map<string, int> book;
    for( string name : phone_book){
        book[name] = book[name] + name.length();
       // cout << book[name] << endl;
    }
    
    
    for(auto itr=book.begin(); itr!=book.end(); itr++)
   {
       int size = itr->second;
      // cout << "size : " << size << endl;
       string str1 = itr->first;
       
       // cout << "str1 : " << str1 << endl;
       
       
   	 	for(auto itr2=book.begin(); itr2 !=book.end(); itr2++){
     		string str2 = itr2->first;
            //cout << "str2 : " << str2 << " " << endl;
            if( str1.compare(str2) != 0 )
            {
                //cout << "in str1 : " << str1 << "in str2 : " << str2 << endl;
               //cout << "compare : " << str1.compare(0, size-1, str2) << endl;
                //cout << "str1.substr : " << str1.substr(0, size) << endl;
                //cout << "str2.substr : " << str2.substr(0, size) << endl;
             
                //substr(0, size) //0에서 size만큼, ex) 0, 3이면 0,1,2임. 즉 총 크기(size == 3),
                //								0,1,2,3이 아니라!!!
                
                //cout << "str1.comp : " << str1.compare(0, size, str2) << endl;
                if( str1.substr(0, size) == str2.substr(0, size) ) 
                //if(str2.find(str1)==0)
                {
                 //cout << "in in str1.comp : " << str1.compare(0, size-1, str2) << endl;  
                 //str1 = "ab", str2 = "abc"
                 //str1.compare(0, 1, str2 ) 
                 //there is compare str1.substr( 0, 1) with str2.
                 //That is there are compared objects "a" and "abc" (*size는 총 크기*)
                    return false;
                }
               
            }
        }
    }  


   return true;
   
}
