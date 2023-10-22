#include <iostream>

struct Number {
private:
    std::string digits;

public:
    explicit Number(std::string &boobs) {
        digits = boobs;
    }

    std::string Digits() {
        return digits;
    }

    Number operator*(Number &other) {
        auto woof = Karabobus(digits, other.digits);
        auto meow = Number(woof);
        return meow;
    }

    std::string Sums(std::string &s1, std::string &s2) {
        std::string res;
        if (s1.size() > s2.size()) {
            Align(s2, s1.size());
        } else if (s1.size() < s2.size()) {
            Align(s1, s2.size());
        }
        if (s1.size() % 2 == 1) {
            s1.insert(0, "0");
            s2.insert(0, "0");
        }
        int flag = 0;
        for (int i = s1.size() - 1; i >= 0; --i) {
            int x = s1[i] - '0';
            int y = s2[i] - '0';
            int summ = x + y + flag;
            res.insert(0, std::to_string(summ % 10));
            if (summ >= 10) {
                flag = 1;
            } else {
                flag = 0;
            }
        }
        if (flag == 1) {
            res.insert(1, std::to_string(flag));
        }
        return res;
    }

    std::string Subs(std::string &s1, std::string &s2) {
        std::string res;
        if (s1.size() > s2.size()) {
            Align(s2, s1.size());
        } else if (s1.size() < s2.size()) {
            Align(s1, s2.size());
        }
        if (s1.size() % 2 == 1) {
            s1.insert(0, "0");
            s2.insert(0, "0");
        }
        int flag = 0;
        for (int i = s1.size() - 1; i >= 0; --i) {
            int x = s1[i] - '0';
            int y = s2[i] - '0';
            int sub = x - y;
            int mx = (sub + 10) % 10 - flag;
            if (mx < 0) {
                mx = (mx + 10) % 10;
            }
            res.insert(0, std::to_string(mx));
            if (sub < 0 || sub == 0 && mx != sub) {
                flag = 1;
            } else {
                flag = 0;
            }
        }
        if (res[0] == '0') {
            res.erase(res.find('0'), 1);
        }
        return res;
    }

    std::string Karabobus(std::string s1, std::string s2) {
        if (s1 == "0" || s2 == "0") {
            return "0";
        }
        if (s1.size() <= 4) {
            int d1 = std::stoi(s1);
            int d2 = std::stoi(s2);
            d1 *= d2;
            return std::to_string(d1);
        }

        if (s1.size() > s2.size()) {
            Align(s2, s1.size());
        } else if (s1.size() < s2.size()) {
            Align(s1, s2.size());
        }
//        if (s1.size() % 2 == 1) {
//            s1.insert(0, "0");
//            s2.insert(0, "0");
//        }

        std::string a2;
        std::string b2;
        std::string a1 = s1.substr(0, s1.size() / 2);
        if (s1.size() % 2 != 0) {
            a2 = s1.substr(s1.size() / 2, s1.size() / 2 + 1);
        } else {
            a2 = s1.substr(s1.size() / 2, s1.size() / 2);
        }

        std::string  b1 = s2.substr(0, s2.size() / 2);
        if (s2.size() % 2 != 0) {
            b2 = s2.substr(s2.size() / 2, s2.size() / 2 + 1);
        } else {
            b2 = s2.substr(s2.size() / 2, s2.size() / 2);
        }


        std::string poop1 = Karabobus(a1, b1);
        std::string poop2 = Karabobus(a2, b2);

        std::string rec1 = Sums(a1, a2);
        std::string rec2 = Sums(b1, b2);

        // attention
        auto yulash = Karabobus(rec1, rec2);
        auto temp = Subs(yulash, poop1);
        // attention
        auto meow = Subs(temp, poop2);
        Norming(poop1, s1.size() + s1.size() % 2);
        Norming(meow, (s1.size() + s1.size() % 2) / 2);
        std::cout << poop1 <<std::endl;
        std::cout << meow <<std::endl;
        std::cout << poop2 <<std::endl;
        std::cout << "___________________________________________" <<std::endl;
        std::string pussy = Sums(poop1, poop2);
        auto result = Sums(pussy, meow);
        while (result[0] == '0') {
            result.erase(result.find('0'), 1);
        }
        return result;
    }

    void Align(std::string &ss, size_t n) {
        size_t difference = n - ss.size();
        for (int i = 0; i < difference; ++i) {
            ss.insert(ss.begin(), '0');
        }
    }

    void Norming(std::string &ss, size_t n) {
        for (int i = 0; i < n; ++i) {
            ss += '0';
        }
    }
};

int main() {
    std::string n1;
    std::string n2;
    std::cin >> n1 >> n2;
    Number num1 = Number(n1);
    Number num2 = Number(n2);
    auto cum = num1 * num2;
    std::cout << cum.Digits();
}
