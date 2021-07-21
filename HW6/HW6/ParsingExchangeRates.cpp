// ParsingExchangeRates.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "ParsingExchangeRates.h"

void parsing()
{
    std::string fileName;
    bool isContinue = true;
    while (isContinue)
    {
        std::cout << "Please give the filename with expansion (ex: \"text.txt\", \"website.html\" or \"HW6.cpp\").\n";
        std::cout << "Enter for exit \"~\"\n";
        std::cin >> fileName;
        std::cout << "\n";
        while (fileName != "~")
        {
            findWord(DOLLAR, fileName);
            findWord(EURO, fileName);
            std::cout << "Please give the filename with expansion (ex: \"text.txt\" or \"HW6.cpp\")\n";
            std::cout << "Enter for exit \"~\"\n";
            std::cin >> fileName;
            std::cout << "\n";
        }
        if (fileName == "~")
            isContinue = false;
    }
    std::cout << "\nEnd of the programme.\n\n";
}

void findWord(std::string word, std::string fileName)
{
    std::string line,
        s;
    std::regex REX{ "[[:d:]][[:d:]][,.][[:d:]]{2,4}" };
    std::string findFile = "find" + fileName;

    size_t countWords = 0,
        foundWords = 0,
        lineNumber = 0,
        coutPos = 0;

    std::ifstream File(fileName.c_str());
    if (File)
    {
        while (!File.eof())
        {
            std::getline(File, line);
            lineNumber++;
            coutPos = line.find(word);

            if (coutPos != std::string::npos)
            {
                std::cout << word << " is at " << lineNumber << ":" << coutPos << "\n";
                countWords++;
                File.close();
                std::ofstream FileOut(findFile.c_str());
                std::ifstream File(fileName.c_str());
                if (File.is_open() && FileOut.is_open())
                {
                    copyFile(File, FileOut, lineNumber, coutPos);
                    File.close();
                    FileOut.close();
                }
            }
            coutPos += word.size();
        }
    }
    else
    {
        std::cout << "Error! File not found!\n";
    }
    if (countWords == 1)
    {

        std::cout << "The word \"" << word << "\" has been found " << countWords << " times.\n\n";
        std::ifstream FileFind(findFile.c_str());
        if (FileFind)
        {
            while (!FileFind.eof())
            {
                std::getline(FileFind, line);
                std::smatch m;
                if (std::regex_search(line, m, REX))
                {
                    std::cout << word << " is ";
                    for (size_t i = 0; i < m.size(); i++)
                    {
                        std::cout << m[i];
                    }
                    std::cout << " RUB \n" << std::endl;
                    FileFind.close();
                    remove(findFile.c_str());
                }
            }

        }
        if (FileFind.bad() == false)
        {
            FileFind.close();
            remove(findFile.c_str());
        }

    }
    else
    {
        std::cout << "The word has not been found.\n\n";
        File.close();
    }

}

void copyFile(std::ifstream& fin, std::ofstream& fout, size_t lineDelete, size_t nPosition)
{
    std::string line;
    size_t lineNumber = 0;

    while (std::getline(fin, line))
    {
        lineNumber++;
        if (lineNumber >= lineDelete)
        {
            if (lineNumber == lineDelete)
                for (size_t i = nPosition; i < line.size(); i++)
                    fout << line[i];
            fout << line << std::endl;
        }
    }
}