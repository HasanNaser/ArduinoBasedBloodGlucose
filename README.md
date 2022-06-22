# BloodGlucoseMeterArduino

Bu repo'da, Arduino UNO'ya dayalı kan şekeri ölçümünü gerçekleştirmek için elektronik bir sistem sunmaya çalışılmıştır.
INA219 akım algılama modülü, glikoz sensöründen gelen sinyalleri Arduino UNO ile voltaj arayüzlerine dönüştürülmesi için kullanılmıştır. LCD modülü, ölçülen kan şekeri değerini görüntülemek için kullanılmıştır. HC06 Arduino Bluetooth Modül ölçülen kan değerinin Bluetooth sinayli üzerinden 3.parti cihazlara göndermek için kullanılmıştır. Yazılım C dilinde Arduino IDE ortamında geliştirilmiştir

### Uygulamanın Akış Diyagramı: 
![Untitled drawing](https://user-images.githubusercontent.com/41211376/175011900-f55f9e96-1b8e-44f2-9bc1-6eed7e99fd9b.png)


Uygulama iki aksamdan oluşuyor:
Donanım aksamı ve yazılım aksamı  

### Donanım Aksamı:
Bileşenler:
- Arduino Uno
- LCD modülü
- INA219 modülü
- HC06 Bluetooth 
- Bio Sensor test şeridi

**Arduino UNO** mikrodenetleyici, programlamayı kolaylaştırmak için sistemin beyni olarak hizmet eder. ATMega328 tabanlı, 14 adet dijital pin girişi (giriş), 6 adet analog üretim girişi (çıkış), 16 MHz seramik rezonatör, USB bağlantısı, güç girişi, ICSP başlığı ve reset butonundan oluşan bir mikrodenetleyici kartıdır.
Kart, Arduino USB kablosu ile bilgisayara bağlayarak desteklemek için gerekli özelliklere sahip. Arduino UNO, USB bağlantısı veya harici bir güç kaynağı ile çalıştırılabilir. Güç kaynağı otomatik olarak seçilir. Harici (USB olmayan) güç, bir AC-DC adaptöründen veya pilden gelebilir. Arduino UNO, Arduino 1.6.4 yazılımı ile programlanabilir. Arduino IDE'de  Araçlar > Anakart menüsünden "Uno'yu seçilerek (karttaki mikro denetleyiciye göre) programlanabilir.  

### Donanım Şeması
![Untitled drawing (2)](https://user-images.githubusercontent.com/41211376/175015715-7bc64d9a-6a95-4348-8462-f441816da9de.png)

Kullanılan biyosensör glukoz test stripleri ön işleme devresine bağlanır. Ön işleme devresi, INA219 devresinden oluşur. Ön işleme devresi, test şeridinden gelen analog sinyali algılar ve sinyali yükseltir ve ardından verileri işlemek için mikro denetleyiciye gönderir. Kullanılan mikrodenetleyici, işlemcisi ATMega328 olan Arduino UNO. arduino'dan işlenen veriler daha sonra I²C protokolü aracılığıyla OLED ekran kullanılarak görüntülenir. ardından bluetooth bağlantısı varsa blutooth üzerinden işlenen veriyi gönderilir, OLED ekranında gösterilecek ve bluetooth üzerinden gönderilecek işlenmiş veriler, kan şekeri seviyesinin ölçümünü temsil edecek.


### Bio Sensor test şeridi
Genellikle test şeritlerine üç elektrot yazdırılır: bir referans eliktrot, bir karşı elektrot ve bir çalışma elektrotu. Sabit bir voltaj uygulanır ve kan uygulandıktan sonra oluşan akım izlenir. Test stripleri markadan markaya değişebileceğinden, bazı modeller kullanıcının test stripleri şişesi üzerinde veya test stripi ile birlikte gelen bir çip üzerinde bulunan bir kodu manuel olarak girmesini gerektirir. Kodlama veya çipin glikoz ölçere girilmesiyle, ölçüm cihazı bu test şeritleri partisine göre kalibre edilecektir. Bu proje için kullanılan test şeritlerinin markası VivaCheck Eco.

![image006](https://user-images.githubusercontent.com/41211376/175030897-5314c4b9-b081-4f4a-9f2e-a0e426c91fe7.png)



### Fotoğraflar

![WhatsApp Image 2022-06-22 at 6 54 12 PM](https://user-images.githubusercontent.com/41211376/175083692-8aee25e3-bf76-4a53-b067-7d5307dad5c8.jpeg)
![WhatsApp Image 2022-06-22 at 6 56 46 PM](https://user-images.githubusercontent.com/41211376/175083706-b98bcbba-e1c2-40a1-8ad4-dac70074e86c.jpeg)
![WhatsApp Image 2022-06-22 at 6 54 03 PM](https://user-images.githubusercontent.com/41211376/175083716-7f7da5f0-e0cc-4e1f-a8a1-4ee78ca8bd31.jpeg)
![WhatsApp Image 2022-06-22 at 6 54 09 PM](https://user-images.githubusercontent.com/41211376/175083719-5f0593aa-628b-43a9-acc0-a24dcf0fe771.jpeg)



Bu çalışmada, kandaki yaklaşık glikoz seviyesini belirlemek için kullanılan Arduino UNO tabanlı sistemin donanım ve yazılım özellikleri anlatılmaktadır. Kan şekeri seviyelerini izlemek için Bio sensör kullanıldı. Gerekli yazılım Arduino 1.6.4 yazılımı kullanılarak C dilinde geliştirilmiştir. Bu çalışmada, test şeritleri kullandık, test şeridine bir damla kan yerleştirildiğinde, şerit üzerindeki elementlerle etkileşime girerek reaksiyona neden olur ve bir elektrik üretilir. Akım, IMA219 akım algılama modülüne gönderilir ve voltaja dönüştürülür. Bu voltaj, daha fazla işlem için Arduino UNO'ya ardından LCD'ye görüntülemek için gönderilir ve 3.parti cihazlara göndermek için bluetooth ile veri transferi gerçekleşir. 
