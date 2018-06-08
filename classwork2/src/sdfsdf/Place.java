package sdfsdf;

import java.util.Objects;

public class Place {
    private byte row;
    private byte seat;

    public Place(int row, int seat) throws IllegalArgumentException {
        if (row <= 0 || seat <= 0) throw new IllegalArgumentException();
        this.row = (byte) row;
        this.seat = (byte) seat;
    }

    public Place() {
        this(0, 0);
    }

    public byte getRow() {
        return row;
    }

    public byte getSeat() {
        return seat;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(row)
                .append(", ")
                .append(seat);
        return sb.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        else if (this == null) return false;
        if (obj instanceof Place) {
            Place pl = (Place) obj;
            return (row == pl.getRow() && seat == pl.getSeat());
        } else return false;
    }

    @Override
    public int hashCode() {
        return ((Integer) (int) row).hashCode() + ((Integer) (int) row).hashCode();
    }
}
