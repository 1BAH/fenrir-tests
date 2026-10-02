
String input_no_numbers = """
        123
        \\w{100}
        \n\t\u1234
        фываёлацз""";

String input_hard = """
        +380 80
        +23424
         +385555888333
        ++3333
        ++33333
        +45 333 333 +45 3333333 +45 33333333333333
        +7 7777777777
        +380999999999
        +381 999999999
        382 999999999
        ++387 123456789
        +49 12345678
        +33333333333 \
        
        8+391234567890=56
        8 + 391234567890 = 56
        """;

List<String> numbers_hard = List.of(
        "+385555888333",
        "+7 7777777777",
        "+380999999999",
        "+381 999999999",
        "+49 12345678",
        "+33333333333"
);

void test(String input, List<String> expected) {
    var real = Regex.getNumbers(input);
    if (!real.equals(expected)) {
        throw new AssertionError("Expected " + expected + " but got " + real);
    }
    System.out.println(" Done");
}


void main() {
    System.out.println("== Running Java tests ==");

    System.out.print("Empty string >> ..");
    test("", Collections.emptyList());

    System.out.print("No valid numbers >> ..");
    test(input_no_numbers, Collections.emptyList());

    System.out.print("Stress test >> ..");
    test(input_hard, numbers_hard);

    System.out.println("== COMPLETED ==");
}
