package cw;

public class Toy {
    private String name;
    private int price;
    private byte lowAgeBorder;
    private byte upAgeBorder;

    public Toy(String name, int price, byte lowAgeBorder, byte upAgeBorder) throws Exception {
        this.price = price;
        if (lowAgeBorder >= 0 && upAgeBorder >= lowAgeBorder) {
            this.lowAgeBorder = lowAgeBorder;
            this.upAgeBorder = upAgeBorder;
        }
        else{
            throw new Exception();
        }
        this.name = name;
    }
    public Toy() throws Exception{
        this("", 0, (byte)0, (byte)0);
    }
    public int getPrice(){
        return this.price;
    }
    public byte getLowAgeBorder(){
        return this.lowAgeBorder;
    }
    public byte getUpAgeBorder(){
        return this.upAgeBorder;
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(name).append(";").append(price).append(";").append(lowAgeBorder).append(";").append(upAgeBorder).append(";\n");
        return sb.toString();
    }

}
