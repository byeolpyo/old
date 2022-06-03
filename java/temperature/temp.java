/* convert a temperature into Celcius, Kelvin and, Fahrenheit units */

/* this program implements a small temperature class that automatically converts the temperature value into all of the available units and provides access to those units */

import java.util.Scanner;

class temperature {
    public temperature(float _temp, String unit) {
        this.setTemp(_temp, unit);
    }

    public float getCels() {
        return this.cels;
    }
    public float getKel() {
        return this.kel;
    }
    public float getFahr() {
        return this.fahr;
    }

    private float cels;
    private float kel;
    private float fahr;

    public void setTemp(float _temp, String unit) {
        if (unit.equalsIgnoreCase("c")) {
            this.cels = _temp;
            this.kel = this.cels + 273.15f;
            this.fahr = this.cels * (float)9/5 + 32;
        }
        else if (unit.equalsIgnoreCase("k")) {
            this.cels = _temp - 273.15f;
            this.kel = _temp;
            this.fahr = this.cels * (float)9/5 + 32;
        }
        else if (unit.equalsIgnoreCase("f")) {
            this.cels = (_temp - 32) * (float)5/9;
            this.kel = this.cels + 273.15f;
            this.fahr = _temp;
        }
    }
}

public class temp {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        System.out.print("input a temperature followed by the unit after a space (\"C\", \"K\", \"F\"): ");
        temperature t = new temperature(inp.nextFloat(), inp.next());

        System.out.println("your temperature in different units: " + t.getCels() + " C, " + t.getKel() + " K, " + t.getFahr() + " F");
        inp.close();
    }
}
