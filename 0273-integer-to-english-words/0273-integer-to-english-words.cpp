class Solution {
public:
    string numberToWords(int num) {
        if(!num) return "Zero";
        string ones[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string teens[10] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string ans = "";
        if(num < 1000){
            if(num >= 100) ans += (ans == "" ? "" : " ") + ones[num/100] + " Hundred";
            if(10 <= num%100 && num%100 < 20){
                ans += (ans == "" ? "" : " ") + teens[num%100-10];
            }else{
                if(num/10%10 > 1) ans += (ans == "" ? "" : " ") + tens[num/10%10];
                if(num%10) ans += (ans == "" ? "" : " ") + ones[num%10];
            }
            return ans;
        }
        if(num/1000000000) ans += (ans == "" ? "" : " ") + numberToWords(num/1000000000) + " Billion";
        if(num/1000000%1000) ans += (ans == "" ? "" : " ") + numberToWords(num/1000000%1000) + " Million";
        if(num/1000%1000) ans += (ans == "" ? "" : " ") + numberToWords(num/1000%1000) + " Thousand";
        if(num%1000) ans += (ans == "" ? "" : " ") + numberToWords(num%1000);
        return ans;
    }
};