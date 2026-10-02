void test(String input, Optional<String> expected) {
    var real = Regex.parseLog(input);
    if (!real.equals(expected)) {
        throw new AssertionError("Expected " + expected + " but got " + real);
    }
}


void main() {
    System.out.println("== Running Java tests ==");

    System.out.print("Empty string >> ..");
    test("", Optional.empty());
    System.out.println(" Done");

    System.out.print("Unquoted >> ..");
    test("sn:qwe nm:qwe", Optional.empty());
    System.out.println(" Done");

    System.out.print("SN-NM >> ..");
    test("sn:\"1\" nm:\"2\"", Optional.of("2-1"));
    System.out.println(" Done");

    System.out.print("NM-SN >> ..");
    test("nm:\"2\" sn:\"1\"", Optional.of("2-1"));
    System.out.println(" Done");

    System.out.print("SN-SN >> ..");
    test("sn:\"1\" sn:\"2\"", Optional.empty());
    System.out.println(" Done");

    System.out.print("NM-NM >> ..");
    test("nm:\"1\" nm:\"2\"", Optional.empty());
    System.out.println(" Done");

    System.out.print("Garbage >> ..");
    test("qwkb, asd;foa;kf sn:\"1\" aklsdfpqb;avisy234- nm:\"2\" al;ij;wb[an", Optional.of("2-1"));
    System.out.println(" Done");

    System.out.print("Empty value >> ..");
    test("sn:\"\" nm:\"\"", Optional.empty());
    test("sn:\"\" nm:\"a\"", Optional.empty());
    test("sn:\"a\" nm:\"\"", Optional.empty());
    System.out.println(" Done");

    System.out.print("Non word chars >> ..");
    test("sn:\"ё\" nm:\"q\"", Optional.empty());
    test("sn:\"q\" nm:\"ё\"", Optional.empty());
    System.out.println(" Done");

    System.out.print("Quotes >> ..");
    test("nm:\"2\" \" sn:\"1\"", Optional.of("2-1"));
    test("nm:\"2\" \" sn:\"1\" \"", Optional.of("2-1"));
    test("sn:\"1\" \" nm:\"2\"", Optional.of("2-1"));
    test("sn:\"1\" \" nm:\"2\" \"", Optional.of("2-1"));
    System.out.println(" Done");

    System.out.print("Prefix >> ..");
    test("asn:\"1\" nm:\"2\"", Optional.empty());
    test("sn:\"1\" anm:\"2\"", Optional.empty());
    test("anm:\"2\" sn:\"1\"", Optional.empty());
    test("nm:\"2\" asn:\"1\"", Optional.empty());
    System.out.println(" Done");


    System.out.println("== COMPLETED ==");
}
