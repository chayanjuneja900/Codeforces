#include<bits/stdc++.h>
using namespace std;

bool check(string a, string b) {
    if (a.length() != 32 || b.length() != 32)
        return false;

    for (int i = 0; i < 32; i++) {
        if (a[i] != '0' && a[i] != '1')
            return false;

        if (b[i] != '0' && b[i] != '1')
            return false;
    }

    return true;
}

bool valid32(const string &s) {
    if (s.size() != 32)
        return false;

    for (char c : s) {
        if (c != '0' && c != '1')
            return false;
    }

    return true;
}

bool isZero(const string &s) {
    for (char c : s) {
        if (c != '0')
            return false;
    }

    return true;
}

bool isAllOne(const string &s) {
    for (char c : s) {
        if (c != '1')
            return false;
    }

    return true;
}

string invertBits(string s) {
    for (char &c : s) {
        if (c == '0')
            c = '1';
        else
            c = '0';
    }

    return s;
}

string inc32(string s) {
    int carry = 1;

    for (int i = 31; i >= 0 && carry; i--) {
        int x = (s[i] - '0') + carry;

        s[i] = char('0' + (x % 2));
        carry = x / 2;
    }

    return s;
}

string addRaw(string a, string b, int &carryOut) {
    string ans(32, '0');
    int carry = 0;

    for (int i = 31; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;

        ans[i] = char('0' + (sum % 2));
        carry = sum / 2;
    }

    carryOut = carry;

    return ans;
}

string add_unsign(string a, string b) {
    if (!check(a, b)) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    int carry;
    string ans = addRaw(a, b, carry);

    if (carry) {
        cout << "Arithmetic overflow" << endl;
        return "";
    }

    return ans;
}

string sub_unsign(string a, string b) {
    if (!check(a, b)) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    if (a < b) {
        cout << "Arithmetic underflow" << endl;
        return "";
    }

    string ans(32, '0');
    int borrow = 0;

    for (int i = 31; i >= 0; i--) {
        int x = (a[i] - '0') - borrow;
        int y = b[i] - '0';

        if (x < y) {
            x += 2;
            borrow = 1;
        }
        else {
            borrow = 0;
        }

        ans[i] = char('0' + x - y);
    }

    return ans;
}

string add_sign(string a, string b) {
    if (!check(a, b)) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    int sa = a[0] - '0';
    int sb = b[0] - '0';

    a[0] = '0';
    b[0] = '0';

    if (sa == sb) {
        int carry;
        string mag = addRaw(a, b, carry);

        if (carry || mag[0] == '1') {
            cout << "Arithmetic overflow" << endl;
            return "";
        }

        if (isZero(mag))
            return string(32, '0');

        mag[0] = char('0' + sa);

        return mag;
    }

    if (a < b) {
        swap(a, b);
        swap(sa, sb);
    }

    string mag = sub_unsign(a, b);

    if (mag.empty())
        return "";

    if (isZero(mag))
        return string(32, '0');

    mag[0] = char('0' + sa);

    return mag;
}

string sub_sign(string a, string b) {
    if (!check(a, b)) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    if (b[0] == '0')
        b[0] = '1';
    else
        b[0] = '0';

    return add_sign(a, b);
}

string add_1comp(string a, string b) {
    if (!check(a, b)) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    int sa = a[0] - '0';
    int sb = b[0] - '0';

    int carry;
    string ans = addRaw(a, b, carry);

    if (carry)
        ans = inc32(ans);

    if (isAllOne(ans))
        return string(32, '0');

    int sr = ans[0] - '0';

    if (sa == sb && sr != sa) {
        cout << "Arithmetic overflow" << endl;
        return "";
    }

    return ans;
}

string sub_1comp(string a, string b) {
    if (!check(a, b)) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    b = invertBits(b);

    return add_1comp(a, b);
}

string add_2comp(string a, string b) {
    if (!check(a, b)) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    int sa = a[0] - '0';
    int sb = b[0] - '0';

    int carry;
    string ans = addRaw(a, b, carry);

    int sr = ans[0] - '0';

    if (sa == sb && sr != sa) {
        cout << "Arithmetic overflow" << endl;
        return "";
    }

    return ans;
}

string sub_2comp(string a, string b) {
    if (!check(a, b)) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    int sa = a[0] - '0';
    int sb = b[0] - '0';

    b = invertBits(b);
    b = inc32(b);

    int carry;
    string ans = addRaw(a, b, carry);

    int sr = ans[0] - '0';

    if (sa != sb && sr != sa) {
        cout << "Arithmetic overflow" << endl;
        return "";
    }

    return ans;
}

string mul_unsign(string a, string b) {
    if (!check(a, b)) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    string ans(32, '0');

    for (int i = 31; i >= 0; i--) {
        if (b[i] == '0')
            continue;

        int shift = 31 - i;

        for (int j = 0; j < shift; j++) {
            if (a[j] == '1') {
                cout << "Arithmetic overflow" << endl;
                return "";
            }
        }

        string temp(32, '0');

        for (int j = 0; j + shift < 32; j++) {
            temp[j] = a[j + shift];
        }

        ans = add_unsign(ans, temp);

        if (ans.empty())
            return "";
    }

    return ans;
}

string mul_sign(string a, string b) {
    if (!check(a, b)) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    int sa = a[0] - '0';
    int sb = b[0] - '0';

    int sign = sa ^ sb;

    a[0] = '0';
    b[0] = '0';

    string ans = mul_unsign(a, b);

    if (ans.empty())
        return "";

    if (ans[0] == '1') {
        cout << "Arithmetic overflow" << endl;
        return "";
    }

    if (isZero(ans))
        return string(32, '0');

    ans[0] = char('0' + sign);

    return ans;
}

string mul_1comp(string a, string b) {
    if (!check(a, b)) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    int sa = a[0] - '0';
    int sb = b[0] - '0';

    int sign = sa ^ sb;

    if (sa)
        a = invertBits(a);

    if (sb)
        b = invertBits(b);

    a[0] = '0';
    b[0] = '0';

    string ans = mul_unsign(a, b);

    if (ans.empty())
        return "";

    if (ans[0] == '1') {
        cout << "Arithmetic overflow" << endl;
        return "";
    }

    if (!sign || isZero(ans))
        return ans;

    return invertBits(ans);
}

string mul_2comp(string a, string b) {
    if (!check(a, b)) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    int sa = a[0] - '0';
    int sb = b[0] - '0';

    int sign = sa ^ sb;

    if (sa)
        a = inc32(invertBits(a));

    if (sb)
        b = inc32(invertBits(b));

    string ans = mul_unsign(a, b);

    if (ans.empty())
        return "";

    if (!sign) {
        if (ans[0] == '1') {
            cout << "Arithmetic overflow" << endl;
            return "";
        }

        return ans;
    }

    if (ans[0] == '1') {
        bool minValue = true;

        for (int i = 1; i < 32; i++) {
            if (ans[i] != '0') {
                minValue = false;
                break;
            }
        }

        if (!minValue) {
            cout << "Arithmetic overflow" << endl;
            return "";
        }
    }

    return inc32(invertBits(ans));
}

string div_unsign(string a, string b) {
    if (!check(a, b)) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    if (isZero(b)) {
        cout << "Error: Division by zero" << endl;
        return "";
    }

    string quotient(32, '0');
    string remainder(33, '0');
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

                remainder[j] = char('0' + x - y);
            }

            quotient[i] = '1';
        }
    }

    return quotient;
}

string div_sign(string a, string b) {
    if (!check(a, b)) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    int sa = a[0] - '0';
    int sb = b[0] - '0';

    int sign = sa ^ sb;

    a[0] = '0';
    b[0] = '0';

    string ans = div_unsign(a, b);

    if (ans.empty())
        return "";

    if (isZero(ans))
        return string(32, '0');

    if (ans[0] == '1') {
        cout << "Arithmetic overflow" << endl;
        return "";
    }

    ans[0] = char('0' + sign);

    return ans;
}

string div_1comp(string a, string b) {
    if (!check(a, b)) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    if (isZero(b) || isAllOne(b)) {
        cout << "Error: Division by zero" << endl;
        return "";
    }

    int sa = a[0] - '0';
    int sb = b[0] - '0';

    int sign = sa ^ sb;

    if (sa)
        a = invertBits(a);

    if (sb)
        b = invertBits(b);

    a[0] = '0';
    b[0] = '0';

    string ans = div_unsign(a, b);

    if (ans.empty())
        return "";

    if (isZero(ans))
        return string(32, '0');

    if (ans[0] == '1') {
        cout << "Arithmetic overflow" << endl;
        return "";
    }

    if (sign)
        ans = invertBits(ans);

    return ans;
}

string div_2comp(string a, string b) {
    if (!check(a, b)) {
        cout << "Invalid binary number" << endl;
        return "";
    }

    if (isZero(b)) {
        cout << "Error: Division by zero" << endl;
        return "";
    }

    int sa = a[0] - '0';
    int sb = b[0] - '0';

    int sign = sa ^ sb;

    if (sa)
        a = inc32(invertBits(a));

    if (sb)
        b = inc32(invertBits(b));

    string ans = div_unsign(a, b);

    if (ans.empty())
        return "";

    if (isZero(ans))
        return string(32, '0');

    if (!sign) {
        if (ans[0] == '1') {
            cout << "Arithmetic overflow" << endl;
            return "";
        }

        return ans;
    }

    if (ans[0] == '1') {
        bool minValue = true;

        for (int i = 1; i < 32; i++) {
            if (ans[i] != '0') {
                minValue = false;
                break;
            }
        }

        if (!minValue) {
            cout << "Arithmetic overflow" << endl;
            return "";
        }
    }

    return inc32(invertBits(ans));
}

int main() {
    string a, b, representation, operation;

    cin >> a;
    cin >> b;
    cin >> representation;
    cin >> operation;

    if (operation == "div") {
        bool validA = true;
        bool validB = true;

        for (char c : a) {
            if (c != '0' && c != '1') {
                validA = false;
                break;
            }
        }

        for (char c : b) {
            if (c != '0' && c != '1') {
                validB = false;
                break;
            }
        }

        if (!validA || !validB) {
            cout << "Invalid binary number" << endl;
            return 0;
        }

        bool zero = isZero(b);

        if (representation == "ones_complement" && isAllOne(b))
            zero = true;

        if (representation == "signed_magnitude" &&
            b.size() == 32 &&
            b[0] == '1') {

            bool negativeZero = true;

            for (int i = 1; i < 32; i++) {
                if (b[i] != '0') {
                    negativeZero = false;
                    break;
                }
            }

            if (negativeZero)
                zero = true;
        }

        if (zero) {
            cout << "Error: Division by zero" << endl;
            return 0;
        }
    }

    if (!valid32(a) || !valid32(b)) {
        cout << "Invalid binary number" << endl;
        return 0;
    }

    if (representation != "unsigned" &&
        representation != "signed_magnitude" &&
        representation != "ones_complement" &&
        representation != "twos_complement") {

        cout << "Invalid representation" << endl;
        return 0;
    }

    if (operation != "add" &&
        operation != "sub" &&
        operation != "mul" &&
        operation != "div") {

        cout << "Invalid operation" << endl;
        return 0;
    }

    string ans;

    if (representation == "unsigned") {
        if (operation == "add")
            ans = add_unsign(a, b);
        else if (operation == "sub")
            ans = sub_unsign(a, b);
        else if (operation == "mul")
            ans = mul_unsign(a, b);
        else
            ans = div_unsign(a, b);
    }

    else if (representation == "signed_magnitude") {
        if (operation == "add")
            ans = add_sign(a, b);
        else if (operation == "sub")
            ans = sub_sign(a, b);
        else if (operation == "mul")
            ans = mul_sign(a, b);
        else
            ans = div_sign(a, b);
    }

    else if (representation == "ones_complement") {
        if (operation == "add")
            ans = add_1comp(a, b);
        else if (operation == "sub")
            ans = sub_1comp(a, b);
        else if (operation == "mul")
            ans = mul_1comp(a, b);
        else
            ans = div_1comp(a, b);
    }

    else {
        if (operation == "add")
            ans = add_2comp(a, b);
        else if (operation == "sub")
            ans = sub_2comp(a, b);
        else if (operation == "mul")
            ans = mul_2comp(a, b);
        else
            ans = div_2comp(a, b);
    }

    if (!ans.empty())
        cout << ans << endl;

    return 0;
}