
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

using std::chrono::system_clock;
using std::string;

class Uhrzeit {

public:
    static string now() {
        system_clock::time_point now = std::chrono::system_clock::now();
        time_t t = system_clock::to_time_t(now);
        tm local_tm = *localtime(&t);
        return toString(local_tm);
    }

    static string toString(const time_t t) {
        tm local_tm = *localtime(&t);
        return toString(local_tm);
    }

    static string toString(const tm time) {
        // Output String
        string o;
        // die Minute
        int m = time.tm_min;
        // die Stunde
        int s = time.tm_hour;

        o += "es ist ";

        if (m == 0) {
            /* Do nothing. */
        } else if (m < 15) {
            o += intToString(m);
            o += " nach";
        } else if (m == 15) {
            o += "viertel nach";
        } else if (m > 15 and m <= 20) {
            o += intToString(m);
            o += " nach";
        } else if (m > 20 and m < 30) {
            o += intToString(m - 20);
            o += " vor halb";
            ++s;
        } else if (m == 30) {
            o += "halb";
            ++s;
        } else if (m > 30 and m <= 40) {
            o += intToString(m - 30);
            o += " nach halb";
            ++s;
        } else if (m > 40 and m < 45) {
            o += intToString(60 - m);
            o += " vor";
            ++s;
        } else if (m == 45) {
            o += "viertel vor";
            ++s;
        } else if (m > 45) {
            o += intToString(60 - m);
            o += " vor";
            ++s;
        }

        if (s == 0) {
            o += "mitternacht";
        } else if (s == 12) {
            o += "mittag";
        } else {
            o += " " + intToString(s);
        }

        return o;
    }

    static string intToString(int n) {
        switch (n) {
            case 0:
                return "null";
            case 1:
                return "eins";
            case 2:
                return "zwei";
            case 3:
                return "drei";
            case 4:
                return "vier";
            case 5:
                return "fünf";
            case 6:
                return "sechs";
            case 7:
                return "sieben";
            case 8:
                return "acht";
            case 9:
                return "neun";
            case 10:
                return "zehn";
            case 11:
                return "elf";
            case 12:
                return "zwölf";
            case 13:
                return "dreizehn";
            case 14:
                return "vierzehn";
            case 15:
                return "fünfzehn";
            case 16:
                return "sechzehn";
            case 17:
                return "siebzehn";
            case 18:
                return "achtzehn";
            case 19:
                return "neunzehn";
            case 20:
                return "zwanzig";
            case 21:
                return "einundzwanzig";
            case 22:
                return "zweiundzwanzig";
            case 23:
                return "dreiundzwanzig";
            default:
                return "";
        }
    }
};

int main() {
    std::cout << Uhrzeit::now() << std::endl;
    return 0;
}