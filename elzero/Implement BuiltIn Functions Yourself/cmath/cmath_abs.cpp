#include <iostream>
float get_float(std::string message = "")
{
    float number = 0;
    do
    {
        // Read a float value from the user
        std::cout << message;
        std::cin >> number;

        // Check if the input was invalid (i.e. not a number)
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            // cout << "Invalid input. Please enter a valid number." << endl;
            continue;
        }
        break;
    } while (true);
    return number;
}
float absolute(float num)
{
    if (num == 0) {
        return 0;
    } else if (num < 0) {
        return -num;
    } else {
        return num;
    }

    // return num == 0? 0 : num < 0? -num : num;
}
int main()
{
    float number = get_float("Enter number to round: ");

    std::cout << "|" << number << "| is " << absolute(number) << "\n";
}