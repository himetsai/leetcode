class Solution {
    public String multiply(String num1, String num2) {
        int[] product = new int[num1.length() + num2.length()];
        for (int i = num1.length() - 1; i >= 0; i--) {
            int d1 = num1.charAt(i) - '0';
            for (int j = num2.length() - 1; j >= 0; j--) {
                int d2 = num2.charAt(j) - '0';
                product[num1.length() - 1 + num2.length() - 1 - (i + j)] += d1 * d2;
            }
        }
        int carry = 0;
        for (int i = 0; i < product.length; i++) {
            product[i] += carry;
            carry = product[i] / 10;
            product[i] %= 10;
        }
        StringBuilder str = new StringBuilder();
        for (int i = product.length - 1; i >= 0; i--) {
            if (product[i] != 0) {
                while (i >= 0) {
                    str.append(product[i--]);

                }
                return str.toString();
            }
        }
        return "0";
    }
}