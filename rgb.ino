int ti=10, t2=50, tin=0, tfi=255;
int r=0, g=0, b=0, rr=255, gg=255, bb=255;
int pr = 5, pg = 6, pb = 9;

void setup() {
  Serial.begin(9600);
  pinMode(pr, OUTPUT);
  pinMode(pg, OUTPUT);
  pinMode(pb, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(pr, HIGH);
  digitalWrite(pg, HIGH);
  digitalWrite(pb, HIGH);
}

void loop() {
  mix();
  //cor();
  //dig();
  //anal();
  delay(t2);
}

void cor() {
  analogWrite(pr, 0);
  analogWrite(pg, 255);
  analogWrite(pb, 0);
}

void mix(){
  ser(r,g,b);
  if (rr<r){
    for (int f1=rr;f1<=r;f1++){
      rr++;
      analogWrite(pr, f1);
      delay(ti);
      ser(f1,r,rr);
    }
  }
  else if (rr>r){
    for (int f2=rr;f2>=r;f2--){
      rr--;
      analogWrite(pr, f2);
      delay(ti);
    }
  }
  //Serial.println("--");
  delay(t2);
  //------------
  if (gg<g){
    for (int f3=gg;f3<=g;f3++){
      gg++;
      analogWrite(pg, f3);
      delay(ti);
    }
  }
  else if (gg>g){
    for (int f4=gg;f4>=g;f4--){
      gg--;
      analogWrite(pg, f4);
      delay(ti);
    }
  }
  //Serial.println("--");
  delay(t2);
  //------------
  if (bb<b){
    for (int f5=bb;f5<=b;f5++){
      bb++;
      analogWrite(pb, f5);
      delay(ti);
    }
  }
  else if (bb>b){
    for (int f6=bb;f6>=b;f6--){
      bb--;
      analogWrite(pb, f6);
      delay(ti);
    }
  }
  //Serial.println("--");
  geraRand(tin, tfi);
}

void anal(){
  geraRand(tin, tfi);
  analogWrite(pr, r);
  analogWrite(pg, g);
  analogWrite(pb, b);
  ser(r,g,b);
}
  
void dig(){
  geraRand(0, 2);
  if(r==1)
    digitalWrite(pr, HIGH);
  else
    digitalWrite(pr, LOW);
  if(g==1)
    digitalWrite(pg, HIGH);
  else
    digitalWrite(pg, LOW);
  if(b==1)
    digitalWrite(pb, HIGH);
  else
    digitalWrite(pb, LOW);
  ser(r,g,b);  
}
//-------------------------------
void ser(int a,int b, int c){
  if (digitalRead(4)==LOW){
    //Serial.println("--");
    if (r!=5000){
      Serial.print("r=");
      Serial.println(a);
    }
    if (g!=5000){
      Serial.print("g=");
      Serial.println(b);
    }
    if (b!=5000){
      Serial.print("b=");
      Serial.println(c);
    }
  Serial.println(" ");
  }
}

void geraRand(int in, int fi){
  r=random(in,fi);
  g=random(in,fi);
  b=random(in,fi);
}

void limpa(){
  digitalWrite(pr, HIGH);
  digitalWrite(pg, HIGH);
  digitalWrite(pb, HIGH);
}
