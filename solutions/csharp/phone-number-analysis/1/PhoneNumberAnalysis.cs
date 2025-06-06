using System;

public static class PhoneNumber
{
    private static string NEW_YORK_AREA_CODE = "212";
    private static string FAKE_AREA_CODE = "555";
    
    public static (bool IsNewYork, bool IsFake, string LocalNumber) Analyze(string phoneNumber)
    {
        string[]phoneNumberParts = phoneNumber.Split("-");
        return (
            IsNewYork: phoneNumberParts[0] == NEW_YORK_AREA_CODE,
            IsFake: phoneNumberParts[1] == FAKE_AREA_CODE,
            LocalNumber: phoneNumberParts[2]
        );
    }

    public static bool IsFake((bool IsNewYork, bool IsFake, string LocalNumber) phoneNumberInfo)
    {
        return phoneNumberInfo.IsFake;
    }
}
