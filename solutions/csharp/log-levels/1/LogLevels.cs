using System;

static class LogLine
{
    public static string Message(string logLine)
    {
        return logLine.Split("]:")[1].Trim();
    }

    public static string LogLevel(string logLine)
    {
        return logLine.Split('[', ']')[1].Trim().ToLower();
    }

    public static string Reformat(string logLine)
    {
        return $"{LogLine.Message(logLine)} ({LogLine.LogLevel(logLine)})";
    }
}
