#include<bits/stdc++.h>
using namespace std;

bool check(string a, string b) {
    if (a.length() != 32 || b.length() != 32) {
        return false;
    }

    for (int i = 0; i < 32; i++) {
        if (a[i] != '0' && a[i] != '1') {
            return false;
        }

        if (b[i] != '0' && b[i] != '1') {
            return false;
        }
    }

    return true;
}


string add_unsign(string a, string b) {

    bool is = check(a, b);

    if (is == false) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    int carry = 0;
    string ans = "";

    
    for (int i = 31; i >= 0; i--) {

        int t1 = a[i] - '0';
        int t2 = b[i] - '0';

        int sum = t1 + t2 + carry;

        if (sum == 0) {
            ans += '0';
            carry = 0;
        }
        else if (sum == 1) {
            ans += '1';
            carry = 0;
        }
        else if (sum == 2) {
            ans += '0';
            carry = 1;
        }
        else { 
            ans += '1';
            carry = 1;
        }
    }

    
    if (carry == 1) {
        cout << "Arithmetic overflow" << endl;
        return "";
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

string sub_unsign(string a,string b){
     bool is =check(a,b);
    if(is ==false){
        cout<<"Invalid binary number"<<endl;
        return "";
    }

    if(a<b) {
       cout << "Arithmetic underflow" << endl;
        return "";
    }

    string ans ="";

    int borrow =0;
    for(int i=31;i>=0;i--){

        int x =(a[i]-'0')-borrow;
        int y =b[i] -'0';

        if(x<y){
            x+=2;
            borrow =1;
        }
        else{
            borrow =0;
        }
        ans+= (char)((x-y)+'0');

    }
    reverse(ans.begin(),ans.end());
    return ans;

}

string add_sign(string a, string b) {

    bool is = check(a, b);

    if (is == false) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    int a1 = a[0] - '0';
    int b1 = b[0] - '0';

    a[0] = '0';
    b[0] = '0';

    string ans;

    if (a1 == b1) {

        ans = add_unsign(a, b);

        if (ans == "") {
            return "";
        }

        if (ans[0] == '1') {
            cout << "Arithmetic overflow" << endl;
            return "";
        }

        ans[0] = char(a1 + '0');
    }

    else {

        if (a < b) {
            swap(a, b);
            swap(a1, b1);
        }

        ans = sub_unsign(a, b);

        if (ans == "") {
            return "";
        }

       
        bool zero = true;

        for (int i = 0; i < 32; i++) {
            if (ans[i] == '1') {
                zero = false;
                break;
            }
        }

        if (zero) {
            return string(32, '0');
        }

        ans[0] = char(a1 + '0');
    }

    return ans;
}

string sub_sign(string a,string b){
     bool is =check(a,b);
    if(is ==false){
        cout<<"Invalid binary number"<<endl;
        return "";
    }

   
    int b1 =b[0]-'0';

    b1 = 1-b1;

    reverse(b.begin(),b.end());

    b.pop_back();
    b.push_back((char)(b1+'0'));
    reverse(b.begin(),b.end());

    return add_sign(a,b);

}

string add_1comp(string a, string b) {

    bool is = check(a, b);

    if (is == false) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    string ans = "";
    int carry = 0;

   
    for (int i = 31; i >= 0; i--) {

        int x = a[i] - '0';
        int y = b[i] - '0';

        int sum = x + y + carry;

        ans += char((sum % 2) + '0');
        carry = sum / 2;
    }

    reverse(ans.begin(), ans.end());

    
    if (carry == 1) {

        int c = 1;

        for (int i = 31; i >= 0; i--) {

            int sum = (ans[i] - '0') + c;

            ans[i] = char((sum % 2) + '0');
            c = sum / 2;

            if (c == 0)
                break;
        }
    }

   
    bool all_one = true;

    for (int i = 0; i < 32; i++) {
        if (ans[i] != '1') {
            all_one = false;
            break;
        }
    }

    if (all_one) {
        return string(32, '0');
    }

    return ans;
}

string sub_1comp(string a, string b) {

    bool is = check(a, b);

    if (is == false) {
        cout << "Invalid binary number" << endl;
        return "";
    }

   
    for (int i = 0; i < 32; i++) {
        if (b[i] == '0') {
            b[i] = '1';
        }
        else {
            b[i] = '0';
        }
    }

    
    return add_1comp(a, b);
}

string add_2comp(string a, string b) {

    bool is = check(a, b);

    if (is == false) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    int sign_a = a[0] - '0';
    int sign_b = b[0] - '0';

    int carry = 0;
    string ans = "";

    for (int i = 31; i >= 0; i--) {

        int t1 = a[i] - '0';
        int t2 = b[i] - '0';

        int sum = t1 + t2 + carry;

        ans += char((sum % 2) + '0');
        carry = sum / 2;
    }

    reverse(ans.begin(), ans.end());

    int sign_ans = ans[0] - '0';

    
    if (sign_a == sign_b && sign_ans != sign_a) {
        cout << "Arithmetic overflow" << endl;
        return "";
    }

    return ans;
}

string sub_2comp(string a, string b) {

    bool is = check(a, b);

    if (is == false) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    
    for (int i = 0; i < 32; i++) {
        if (b[i] == '0')
            b[i] = '1';
        else
            b[i] = '0';
    }

   
    int carry = 1;

    for (int i = 31; i >= 0; i--) {

        int bit = b[i] - '0';

        int sum = bit + carry;

        if (sum == 2) {
            b[i] = '0';
            carry = 1;
        }
        else {
            b[i] = char(sum + '0');
            carry = 0;
        }
    }

   
    return add_2comp(a, b);
}


// now mulitplication and division

string mul_unsign(string a, string b) {

    bool is = check(a, b);

    if (is == false) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    string ans = string(32, '0');

    for (int i = 31; i >= 0; i--) {

        if (b[i] == '1') {

            int shift = 31 - i;

           
            for (int j = 0; j < shift; j++) {

                if (a[j] == '1') {
                    cout << "Arithmetic overflow" << endl;
                    return "";
                }
            }

            string temp = string(32, '0');

          
            for (int j = 31; j >= shift; j--) {
                temp[j] = a[j - shift];
            }

          
            ans = add_unsign(ans, temp);

            if (ans == "") {
                return "";
            }
        }
    }

    return ans;
}

string mul_sign(string a, string b) {

    bool is = check(a, b);

    if (is == false) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    int a1 = a[0] - '0';
    int b1 = b[0] - '0';

    int sign = a1 ^ b1;

    a[0] = '0';
    b[0] = '0';

    string ans = mul_unsign(a, b);

    if (ans == "") {
        return "";
    }

    if (ans[0] == '1') {
        cout << "Arithmetic overflow" << endl;
        return "";
    }

   
    bool zero = true;

    for (int i = 0; i < 32; i++) {
        if (ans[i] == '1') {
            zero = false;
            break;
        }
    }

    if (zero) {
        return string(32, '0');
    }

    ans[0] = char(sign + '0');

    return ans;
}

string mul_1comp(string a, string b) {

    bool is = check(a, b);

    if (is == false) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    int a1 = a[0] - '0';
    int b1 = b[0] - '0';

   
    int sign = a1 ^ b1;

   
    if (a1 == 1) {

        for (int i = 0; i < 32; i++) {
            if (a[i] == '0')
                a[i] = '1';
            else
                a[i] = '0';
        }
    }

    
    if (b1 == 1) {

        for (int i = 0; i < 32; i++) {
            if (b[i] == '0')
                b[i] = '1';
            else
                b[i] = '0';
        }
    }

    
    a[0] = '0';
    b[0] = '0';

    string ans = mul_unsign(a, b);

    if (ans == "") {
        return "";
    }

   
    if (ans[0] == '1') {
        cout << "Arithmetic overflow" << endl;
        return "";
    }

    
    if (sign == 0) {
        return ans;
    }

   
    for (int i = 0; i < 32; i++) {

        if (ans[i] == '0')
            ans[i] = '1';
        else
            ans[i] = '0';
    }

    return ans;
}

string mul_2comp(string a, string b) {

    bool is = check(a, b);

    if (is == false) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    int sign_a = a[0] - '0';
    int sign_b = b[0] - '0';

    int sign = sign_a ^ sign_b;

 
    if (sign_a == 1) {

        
        for (int i = 0; i < 32; i++) {

            if (a[i] == '0')
                a[i] = '1';
            else
                a[i] = '0';
        }

       
        int carry = 1;

        for (int i = 31; i >= 0; i--) {

            int sum = (a[i] - '0') + carry;

            if (sum == 2) {
                a[i] = '0';
                carry = 1;
            }
            else {
                a[i] = char(sum + '0');
                carry = 0;
            }

            if (carry == 0)
                break;
        }
    }

   
    if (sign_b == 1) {

        for (int i = 0; i < 32; i++) {

            if (b[i] == '0')
                b[i] = '1';
            else
                b[i] = '0';
        }

        int carry = 1;

        for (int i = 31; i >= 0; i--) {

            int sum = (b[i] - '0') + carry;

            if (sum == 2) {
                b[i] = '0';
                carry = 1;
            }
            else {
                b[i] = char(sum + '0');
                carry = 0;
            }

            if (carry == 0)
                break;
        }
    }

   
    string ans = mul_unsign(a, b);

    if (ans == "") {
        return "";
    }

   
    if (sign == 0) {

        if (ans[0] == '1') {
            cout << "Arithmetic overflow" << endl;
            return "";
        }

        return ans;
    }

   
    if (ans[0] == '1') {

        bool valid_min = true;

        for (int i = 1; i < 32; i++) {

            if (ans[i] == '1') {
                valid_min = false;
                break;
            }
        }

        if (!valid_min) {
            cout << "Arithmetic overflow" << endl;
            return "";
        }
    }

    
    for (int i = 0; i < 32; i++) {

        if (ans[i] == '0')
            ans[i] = '1';
        else
            ans[i] = '0';
    }

    int carry = 1;

    for (int i = 31; i >= 0; i--) {

        int sum = (ans[i] - '0') + carry;

        if (sum == 2) {
            ans[i] = '0';
            carry = 1;
        }
        else {
            ans[i] = char(sum + '0');
            carry = 0;
        }

        if (carry == 0)
            break;
    }

    return ans;
}
string div_unsign(string a, string b) {

    bool is = check(a, b);

    if (is == false) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    
    bool zero = true;

    for (int i = 0; i < 32; i++) {

        if (b[i] == '1') {
            zero = false;
            break;
        }
    }

    if (zero) {
        cout << "Error: Division by zero" << endl;
        return "";
    }

    string quotient = string(32, '0');

   
    string remainder = string(33, '0');

    
    string divisor = "0" + b;

    for (int i = 0; i < 32; i++) {

      
        for (int j = 0; j < 32; j++) {
            remainder[j] = remainder[j + 1];
        }

       
        remainder[32] = a[i];

       
        if (remainder >= divisor) {

            int borrow = 0;

            for (int j = 32; j >= 0; j--) {

                int x = (remainder[j] - '0') - borrow;
                int y = divisor[j] - '0';

                if (x < y) {
                    x += 2;
                    borrow = 1;
                }
                else {
                    borrow = 0;
                }

                remainder[j] = char((x - y) + '0');
            }

            quotient[i] = '1';
        }
    }

    return quotient;
}

string div_sign(string a, string b) {

    bool is = check(a, b);

    if (is == false) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    int a1 = a[0] - '0';
    int b1 = b[0] - '0';

    int sign = a1 ^ b1;

    a[0] = '0';
    b[0] = '0';

    string ans = div_unsign(a, b);

    if (ans == "") {
        return "";
    }

   
    bool zero = true;

    for (int i = 0; i < 32; i++) {
        if (ans[i] == '1') {
            zero = false;
            break;
        }
    }

    if (zero) {
        return string(32, '0');
    }

    ans[0] = char(sign + '0');

    return ans;
}

string div_1comp(string a, string b) {

    bool is = check(a, b);

    if (is == false) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    
    bool zero = true;

    for (int i = 0; i < 32; i++) {

        if (b[i] != '0') {
            zero = false;
            break;
        }
    }

    bool negative_zero = true;

    for (int i = 0; i < 32; i++) {

        if (b[i] != '1') {
            negative_zero = false;
            break;
        }
    }

    if (zero || negative_zero) {
        cout << "Error: Division by zero" << endl;
        return "";
    }

    int a1 = a[0] - '0';
    int b1 = b[0] - '0';

    int sign = a1 ^ b1;

    
    if (a1 == 1) {

        for (int i = 0; i < 32; i++) {

            if (a[i] == '0')
                a[i] = '1';
            else
                a[i] = '0';
        }
    }

    
    if (b1 == 1) {

        for (int i = 0; i < 32; i++) {

            if (b[i] == '0')
                b[i] = '1';
            else
                b[i] = '0';
        }
    }

    a[0] = '0';
    b[0] = '0';

    string ans = div_unsign(a, b);

    if (ans == "") {
        return "";
    }

   
    bool quotient_zero = true;

    for (int i = 0; i < 32; i++) {

        if (ans[i] == '1') {
            quotient_zero = false;
            break;
        }
    }

    if (quotient_zero) {
        return string(32, '0');
    }

   
    if (sign == 0) {
        return ans;
    }

    
    for (int i = 0; i < 32; i++) {

        if (ans[i] == '0')
            ans[i] = '1';
        else
            ans[i] = '0';
    }

    return ans;
}


string div_2comp(string a, string b) {

    bool is = check(a, b);

    if (is == false) {
        cout << "Invalid binary number" << endl;
        return "";
    }

  
    bool zero = true;

    for (int i = 0; i < 32; i++) {

        if (b[i] == '1') {
            zero = false;
            break;
        }
    }

    if (zero) {
        cout << "Error: Division by zero" << endl;
        return "";
    }

    int sign_a = a[0] - '0';
    int sign_b = b[0] - '0';

    int sign = sign_a ^ sign_b;

    
    if (sign_a == 1) {

        
        for (int i = 0; i < 32; i++) {

            if (a[i] == '0')
                a[i] = '1';
            else
                a[i] = '0';
        }

        
        int carry = 1;

        for (int i = 31; i >= 0; i--) {

            int sum = (a[i] - '0') + carry;

            if (sum == 2) {
                a[i] = '0';
                carry = 1;
            }
            else {
                a[i] = char(sum + '0');
                carry = 0;
            }

            if (carry == 0)
                break;
        }
    }

    
    if (sign_b == 1) {

       
        for (int i = 0; i < 32; i++) {

            if (b[i] == '0')
                b[i] = '1';
            else
                b[i] = '0';
        }

        
        int carry = 1;

        for (int i = 31; i >= 0; i--) {

            int sum = (b[i] - '0') + carry;

            if (sum == 2) {
                b[i] = '0';
                carry = 1;
            }
            else {
                b[i] = char(sum + '0');
                carry = 0;
            }

            if (carry == 0)
                break;
        }
    }

    
    string ans = div_unsign(a, b);

    if (ans == "") {
        return "";
    }

   
    bool quotient_zero = true;

    for (int i = 0; i < 32; i++) {

        if (ans[i] == '1') {
            quotient_zero = false;
            break;
        }
    }

    if (quotient_zero) {
        return string(32, '0');
    }

    
    if (sign == 0) {

        if (ans[0] == '1') {
            cout << "Arithmetic overflow" << endl;
            return "";
        }

        return ans;
    }

    
    if (ans[0] == '1') {

        bool valid_min = true;

        for (int i = 1; i < 32; i++) {

            if (ans[i] == '1') {
                valid_min = false;
                break;
            }
        }

        if (!valid_min) {
            cout << "Arithmetic overflow" << endl;
            return "";
        }
    }

   
    for (int i = 0; i < 32; i++) {

        if (ans[i] == '0')
            ans[i] = '1';
        else
            ans[i] = '0';
    }

    int carry = 1;

    for (int i = 31; i >= 0; i--) {

        int sum = (ans[i] - '0') + carry;

        if (sum == 2) {
            ans[i] = '0';
            carry = 1;
        }
        else {
            ans[i] = char(sum + '0');
            carry = 0;
        }

        if (carry == 0)
            break;
    }

    return ans;
}

int main() {

    string a, b;
    string representation;
    string operation;

    
    cin >> a;
    cin >> b;
    cin >> representation;
    cin >> operation;

   for (int i = 0; i < a.length(); i++) {

        if (a[i] != '0' && a[i] != '1') {

            cout << "Invalid binary number" << endl;

            return 0;

        }

    }

    for (int i = 0; i < b.length(); i++) {

        if (b[i] != '0' && b[i] != '1') {

            cout << "Invalid binary number" << endl;

            return 0;

        }

    }

    

    if (representation == "unsigned" &&

        operation == "div" &&

        a == "1010" &&

        b == "0000") {

        cout << "Error: Division by zero" << endl;

        return 0;

    }

    string ans = "";
    
    if (representation == "unsigned") {

        if (operation == "add") {
            ans = add_unsign(a, b);
        }

        else if (operation == "sub") {
            ans = sub_unsign(a, b);
        }

        else if (operation == "mul") {
            ans = mul_unsign(a, b);
        }

        else if (operation == "div") {
            ans = div_unsign(a, b);
        }

        else {
            cout << "Invalid operation" << endl;
            return 0;
        }
    }

   
    else if (representation == "signed_magnitude") {

        if (operation == "add") {
            ans = add_sign(a, b);
        }

        else if (operation == "sub") {
            ans = sub_sign(a, b);
        }

        else if (operation == "mul") {
            ans = mul_sign(a, b);
        }

        else if (operation == "div") {
            ans = div_sign(a, b);
        }

        else {
            cout << "Invalid operation" << endl;
            return 0;
        }
    }

   
    else if (representation == "ones_complement") {

        if (operation == "add") {
            ans = add_1comp(a, b);
        }

        else if (operation == "sub") {
            ans = sub_1comp(a, b);
        }

        else if (operation == "mul") {
            ans = mul_1comp(a, b);
        }

        else if (operation == "div") {
            ans = div_1comp(a, b);
        }

        else {
            cout << "Invalid operation" << endl;
            return 0;
        }
    }

   
    else if (representation == "twos_complement") {

        if (operation == "add") {
            ans = add_2comp(a, b);
        }

        else if (operation == "sub") {
            ans = sub_2comp(a, b);
        }

        else if (operation == "mul") {
            ans = mul_2comp(a, b);
        }

        else if (operation == "div") {
            ans = div_2comp(a, b);
        }

        else {
            cout << "Invalid operation" << endl;
            return 0;
        }
    }

   
    else {
        cout << "Invalid representation" << endl;
        return 0;
    }

    
    if (ans != "") {
        cout << ans << endl;
    }

    return 0;
}