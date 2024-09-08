#include <string>
#include <iostream>

    std::string convert_to_b_string(int n_data) {
        std::string bits = "";
        

        while (n_data != 0) {
            bits.insert(bits.begin(), (n_data % 2) + '0');
            n_data /= 2;
        }

        return bits;
    }

    std::string convertDateToBinary(std::string date) {

        std::string year = date.substr(0, 4);
        std::string month = date.substr(5, 2);
        std::string day = date.substr(8, 2);

        int n_year = std::stoi(year);
        int n_month = std::stoi(month);
        int n_day = std::stoi(day);

        std::string b_year = convert_to_b_string(n_year);
        std::string b_month = convert_to_b_string(n_month);
        std::string b_day = convert_to_b_string(n_day);

        return b_year + "-" + b_month + "-" + b_day;
    }

int main() {
    std::cout<< convertDateToBinary("1900-01-01")<<std::endl;
    std::cout<< convertDateToBinary("2080-02-29")<<std::endl;

    return 
}