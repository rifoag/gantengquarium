class test {
  public static void main(String[] arg){
    try {
      int i = 1/0;
      System.out.println(i);
    } catch (Exception e){
      System.out.println(e);
    } finally {
      System.out.println("hi");
    }

  }
}
