class Solution {
    public String intToRoman(int num) {
        char[] t = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        StringBuilder roman = new StringBuilder();
        int i = 0;
        while (num > 0) {
            int digit = num % 10;
            switch (digit) {
                case 0:
                case 1: 
                case 2: 
                case 3: 
                    while (digit-- > 0) roman.insert(0, t[i]);
                    break;
                case 4:
                    roman.insert(0, t[i+1]);
                    roman.insert(0, t[i]);
                    break;
                case 5: 
                case 6: 
                case 7: 
                case 8:
                    while (digit-- > 5) roman.insert(0, t[i]);
                    roman.insert(0, t[i+1]);
                    break;
                default:
                    roman.insert(0, t[i+2]);
                    roman.insert(0, t[i]);
                    break;
            }
            i += 2;
            num /= 10;
        }
        return roman.toString();
    }
}