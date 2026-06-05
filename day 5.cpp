QUES VALID PALINDROME
class Solution {
public:
char lowert(int ch){
    char temp;
    if(ch>='a' && ch<='z'){
       return ch;
    }
    else{
        temp= ch-'A'+'a';
        return temp;
    }
    return ch;
}
    bool isPalindrome(string s) {
        int n=s.size();
        int st=0;
        int e=n-1;
        while(st<e){
            if(!isalnum(s[st])){
                st++;
                continue;
            }
            if(!isalnum(s[e])){
                e--;
                continue;
            }

            if(lowert(s[st])!=lowert(s[e])){
                return 0;
            }
                st++;
                e--;
            
        }
        return 1;
    }
};
QUES REVERSE STRING
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int st=0;
        int e=n-1;
        while(st<e){
            swap(s[st++],s[e--]);
        }
    }
};
QUES LONGEST COMMON PREFIX
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs[strs.size() - 1];

        string result = "";

        for (int i = 0; i < min(first.length(), last.length()); i++) {
            if (first[i] != last[i]) {
                break;
            }
            result += first[i];
        }

        return result;
    }
};
QUES 5 OOPS
The methods in the AdultUser class should perform the following logic.
registerAccount function:
if age > 12, a message displaying “You have successfully registered under an Adult Account”
should be displayed in the console.
If age<12, a message displaying, “Sorry, Age must be greater than 12 to register as an adult”
should be displayed in the console.
requestBook function:
if bookType is “Fiction”, a message displaying “Book Issued successfully, please return the book
within 7 days” should be displayed in the console.
Else, a message displaying, “Oops, you are allowed to take only adult Fiction books” should be
displayed in the console.
  ANS 
  class AdultUser implements LibraryUser {
    private int age;
    private String bookType;

    @Override
    public void registerAccount(int age) {
        this.age = age;

        if (age > 12) {
            System.out.println("You have successfully registered under an Adult Account");
        } else {
            System.out.println("Sorry, Age must be greater than 12 to register as an adult");
        }
    }

    @Override
    public void requestBook(String bookType) {
        this.bookType = bookType;

        if (bookType.equalsIgnoreCase("Fiction")) {
            System.out.println("Book Issued successfully, please return the book within 7 days");
        } else {
            System.out.println("Oops, you are allowed to take only adult Fiction books");
        }
    }
}
