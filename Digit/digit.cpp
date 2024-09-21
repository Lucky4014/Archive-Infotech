// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>

using namespace std;







string oneToNineteen[] = {
    "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
    "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
    "Seventeen", "Eighteen", "Nineteen"
};

string tens[] = {
    "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
};

string thousands[] = {
    "", "Thousand", "Million"
};

string convertToWords(int num) {
    if (num == 0) return "Zero";
    
    string words = "";

    if (num >= 1000000) {
        words += convertToWords(num / 1000000) + " Million";
        num %= 1000000;
    }
    
    if (num >= 1000) {
        words += convertToWords(num / 1000) + " Thousand ";
        num %= 1000;
    }

    if (num >= 100) {
        words += oneToNineteen[num / 100] + " Hundred ";
        num %= 100;
    }

    if (num >= 20) {
        words += tens[num / 10];
        if (num % 10 != 0) words += " " + oneToNineteen[num % 10];
    } else if (num > 0) {
        words += oneToNineteen[num];
    }

    return words;
}

int main() {
    int number;
    cout << "Enter a number between 1 and 99,999,999: ";
    cin >> number;

    if (number < 1 || number > 99999999) {
        cout << "Number out of range" << endl;
    } else {
        cout << convertToWords(number) << endl;
    }

    return 0;
}



//output
//Enter a number between 1 and 99,999,999: 6000
//Six Thousand


