#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include <stdexcept>
#include <vector>

class RoboRun {
private:
    double x_coord, y_coord;
    std::vector<std::pair<std::string, double>> command_history;
    std::vector<std::pair<double, double>> coord_history;

public:
    RoboRun() : x_coord(0), y_coord(0) {
        coord_history.emplace_back(x_coord, y_coord);
    }

    

    // Метод для обработки команд
    void processCommand(const std::string& command) {
        std::istringstream iss(command);
        std::string direction;
        double value;

        if (!(iss >> direction >> value)) {
            throw std::invalid_argument("Invalid command format");
        }

        for (auto& c : direction) c = std::tolower(c);// Приведение команды к нижнему регистру


        if (direction == "gon") {
            y_coord += value;
        }
        else if (direction == "gos") {
            y_coord -= value;
        }
        else if (direction == "gow") {
            x_coord -= value;
        }
        else if (direction == "goe") {
            x_coord += value;
        }
        else {
            throw std::invalid_argument("Invalid direction");
        }

        
        command_history.emplace_back(direction, value);// Сохранене команду и координаты после ее выполнения
        coord_history.emplace_back(x_coord, y_coord);
    }

    void printCoord() const {
        std::cout << "Current coordinates: (" << x_coord << ", " << y_coord << ")\n";
    }

    void GoRun(double x_start) {
        x_coord = x_start;
        command_history.clear();
        coord_history.clear();
        coord_history.emplace_back(x_coord, y_coord);
    }

    void rev(int N) {
        if (N > static_cast<int>(command_history.size())) {
            throw std::out_of_range("Cannot revert more commands than executed");
        }

        
        //coord_history.resize(coord_history.size() - N);//возвращаем координаты на Н операций назад
        //auto [prev_x, prev_y] = coord_history.back();
        //x_coord = prev_x;
        //y_coord = prev_y;

        command_history.resize(command_history.size() - N);//удаляем из истории лтмененные координаты 
    }
};

int main() {
    RoboRun robot;
    std::string command;

    while (true) {
        std::cout << "Enter command: ";
        std::getline(std::cin, command);

        try {
            if (command.substr(0, 3) == "Rev") {
                int N = std::stoi(command.substr(4));
                robot.rev(N);
            }
            else {
                robot.processCommand(command);
            }
            robot.printCoord();
        }
        catch (const std::invalid_argument& e) {
            std::cerr << e.what() << std::endl;
        }
        catch (const std::out_of_range& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    return 0;
}
