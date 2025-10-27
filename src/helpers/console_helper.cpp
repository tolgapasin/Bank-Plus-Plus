#include <iostream>
#include <iomanip>

class ConsoleHelper {
    public:
        void Print(const std::string& statement) {
            std::cout << statement << std::endl;
            std::cout << std::endl;
        }

        void Print(const std::vector<std::string>& statements) {
            for (std::string statement: statements) {
                std::cout << statement << std::endl;
            }

            std::cout << std::endl;
        }

        void PrintPreciseDouble(const std::string& statement, double value, int precision) {
            std::cout << std::fixed << std::setprecision(precision);
            std::cout << statement << value << std::endl;
            std::cout << std::endl;
        }

        template <typename T>
        T GetInput() {
            T input;
            std::cin >> input;
            input = ValidateInputType<T>(input);
            std::cout << std::endl;
            return input;
        }

        void ClearConsole() {
            std::system("clear");
        }

    private:
        template <typename T>
        T ValidateInputType(T& input) {
            if (std::cin.fail()) {
                std::cout << std::endl;
                std::cout << "Invalid input, please enter a " << GetHumanReadableFromTypeId(typeid(T).name());
                std::cout << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << std::endl;

                std::cin >> input;
            }

            return input;
        }

        std::string GetHumanReadableFromTypeId(const std::string& typeId) {
            if (typeId == "i") return "non-decimal number";
            if (typeId == "d") return "number";
            return "unknown";
        }
};