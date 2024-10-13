using System;

class Program
{
    static void PrintHighlighted(string input, string substring, int start, int end)
    {
        Console.Write(input.Substring(0, start));
        Console.Write($"({substring})");
        Console.WriteLine(input.Substring(end + 1));
    }

    static void Main()
    {
        string input = "29535123p48723487597645723645";
        int len = input.Length;
        long total = 0;

        for (int i = 0; i < len; i++)
        {
            if (Char.IsDigit(input[i]))
            {
                for (int j = i + 1; j < len; j++)
                {
                    if (Char.IsDigit(input[j]) && input[i] == input[j])
                    {
                        bool valid = true;
                        for (int k = i + 1; k < j; k++)
                        {
                            if (!Char.IsDigit(input[k]) || input[k] == input[i])
                            {
                                valid = false;
                                break;
                            }
                        }
                        if (valid)
                        {
                            string substring = input.Substring(i, j - i + 1);
                            PrintHighlighted(input, substring, i, j);
                            total += long.Parse(substring);
                        }
                    }
                    if (!Char.IsDigit(input[j]))
                        break;
                }
            }
        }

        Console.WriteLine($"\nTotal = {total}");
    }
}