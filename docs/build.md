# chromatonemini Build Guide for rev.01 and rev.02

**一度すべて読んでから組み立てることをお勧めします。**

rev.02 では、以下が変更になっています
- ロゴが入りました
- サスティンペダル入力用のコネクタを追加
- リセットスイッチの位置を変更。
- ボトムプレートにもUSB部分に切り欠きを入れたので、より多くのUSBケーブルが干渉しなくなると思います。
- LEDの「辛さ」が117段階選択可能に。  
「辛口」のSK6812miniに加え、「中辛」のSK6812mini-Eが実装できるようになりました。混在可能なのでお好みの「辛さ」調整が可能にw

※ rev.01 の基板をお持ちの方で、サスティンペダルを接続するための改造方法について、rev.01 のビルドガイドに追記しました。  
詳細は[こちら](https://github.com/3araht/chromatonemini/blob/main/docs/build_r01.md#4-5) をご覧ください。  



## 0 ##
## パーツの確認、各部品の実装面の整理 ###
### キット付属品

| パーツ名 |  個数  |  備考  |
|--------|-------|-------|  
|基板|1枚||
|ボトムプレート|1枚||
|M2 スペーサー |26個||
|M2 ネジ|52個||
|クッションシール|15個||
|リセットスイッチ|1個|ファームウェアを書き込むときに使います。|
|タクトスイッチ|37個|主にグリッサンド奏法で用いる半音階キー用。※	華奢なので演奏は優しくお願いします。|
|(rev.02以降)TRRS コネクタ|1個|サスティンペダル接続用|
|ダイオード 1N4148|42個|音階キー用37個＋操作ボタン用4個＋ロータリーエンコーダー用1個|


### 別途用意いただく必要のあるもの

| パーツ名 |  個数  |  備考  |
|--------|-------|--------|  
|[Pro Micro （コンスルー付き）](https://yushakobo.jp/shop/promicro-spring-pinheader/)|1個|ファームウェア なし をお選びください（別途書き込みます）。|
|キースイッチ(CherryMX 互換品)|115個|5pin タイプ推奨。音階キー111個＋操作ボタン4個用。|
|MX対応キーキャップ|115個|1U。音階キー111個＋操作ボタン4個用。|
|[ロータリーエンコーダ(ノブ付き)](https://yushakobo.jp/shop/pec12r-4222f-s0024/)|1個|押しボタン機能付きのものを選んでください（端子が上に2本（押しボタン用）、下に3本（エンコーダー用）生えてるやつ）。長押し＋〇〇でレイヤー切り替え。|
|MicroUSBケーブル|1本|Pro Micro 側のコネクタの耐久性が低いためマグネット式を推奨。Pro Micro にファームウェア書き込むときにとても便利です。また、データ通信ができるケーブルである必要がありますので、充電用のケーブルは使えません。Hex ファイルが書き込みできなかったらケーブルを確認してみてください。|

### [Optional]別途用意いただく必要のあるもの

| パーツ名 |  個数  |  備考  |
|--------|-------|-------|
|(rev.01)LED SK6812mini|116個|音階キー111個＋操作ボタン4個＋エンコーダ用1個。2の「Backlight RGB LED」を使う場合に必要。難しい半田付けを伴うので、半田付け初心者の方はLEDなしで組み立てられることをお勧め致します。|
|(rev.02以降)LED: SK6812mini(辛口) or/and SK6812mini-E (中辛)|116個|音階キー111個＋操作ボタン4個＋エンコーダ用1個 辛さが０辛＝全部中辛 〜 116辛＝全部辛口に調整可能♪|
|(rev.02以降)サスティンペダル|1台|ノーマリオフタイプ。念の為、極性変換スイッチつきのものをおすすめします。|
|(rev.02以降)3.5 mm ミニジャック変換ケーブル|1本|サスティンペダルのモノラルジャックを TRRS コネクタに刺さるように変換します。|

### オモテ面、裏面の実装物

**※ 部品の実装には順番があります。特に、Pro Micro、キースイッチ、エンコーダ、の実装は最後になりますので先に実装しないよう注意ください。
実装の順番はこの後の手順に従ってください。**

オモテ面  
<img width="700" alt="PCB" src="https://github.com/3araht/chromatonemini/blob/main/pictures/front_pcb_r01.jpg">

裏面  

基板の裏面には、ダイオードの実装場所やキーボード名が印字されています。  
<img width="700" alt="PCB" src="https://github.com/3araht/chromatonemini/blob/main/pictures/rear_pcb_r01.jpg">


#### 裏面には次の部品を実装します
 - ダイオード
 - リセットスイッチ
 - Pro Micro (実はオモテ面にも実装可能です。もし、裏面に実装したときにUSBのコネクタが干渉しそうでしたら、オモテ面に実装してください。)
 - (rev.02 以降)TRRS コネクタ
 - LED[Optional]

#### オモテ面には次の部品を実装します
 - キースイッチ
 - タクトスイッチ
 - エンコーダ


## 1
## ダイオードの取付け ##
キーの数が多いキーボードではMatrixという手法を使ってキーが押されたかどうか判断します。
キーが必ず1個ずつしか押されないと保証されているのであれば、このダイオードは不要なのですが、
和音を弾くことがあるので複数のキーを同時に押す場面が出てきます。
このとき、Matrixという手法で複数同時押しを正しく判断するためにこのダイオードが必要になります。
詳しい説明については、[こちら](https://docs.qmk.fm/#/how_a_matrix_works)などをご覧ください。

ダイオードには向きがあります。また、図のように足を曲げておきます。
ダイオードをつまんで両端の足を同時に曲げると図の右のように比較的ちょうどいい形になります。  
<img width="700" alt="diode" src="https://github.com/3araht/chromatonemini/blob/main/pictures/diode_bend.jpg">

キースイッチと干渉しないように、ダイオードは基板の裏面に実装します。
ダイオードの黒い線のほうが四角いフットプリント（Kと印字されている方, K はKathode（独）の頭文字らしいですが、黒（Kuro) の K で。）に合うように配置します。  
<img width="700" alt="diode" src="https://github.com/3araht/chromatonemini/blob/main/pictures/diode_align1.jpg">

足を曲げて基板に這わせてダイオードを仮止めします。  
<img width="700" alt="diode" src="https://github.com/3araht/chromatonemini/blob/main/pictures/diode_flatten.jpg">

オモテ面から見た図  
<img width="700" alt="diode" src="https://github.com/3araht/chromatonemini/blob/main/pictures/diode_flatten2.jpg">

オモテ面から半田付けします。  
<img width="700" alt="diode" src="https://github.com/3araht/chromatonemini/blob/main/pictures/diode_soldered.jpg">

足をニッパでカットします（同上）。足は勢いよく飛んで行くので、足を押さえながら切ると良いです。  
<img width="700" alt="diode" src="https://github.com/3araht/chromatonemini/blob/main/pictures/diode_feet_cut.jpg">

これをD01 〜 D42 の42箇所半田付けします。

## 2 ##
## Backlight RGB LEDの取付け[Optional] ##
イメージトレーニングが重要なので、まずは ”SK6812mini はんだ付け” で半田付けの様子を紹介している動画をチェックしてみてください。  
また、以下を使うことが成功の鍵となります。  
- 温度調整機能付き半田ごてで温度を200℃〜220℃に設定する
- 融点の低い 鉛入り半田（共晶半田）を使う

こちらの[SK6812mini 半田付け事例](https://youtu.be/iu1ekWnexwM) も参考にしていただけたら幸いです。

**以下はrev.01 の基板に SK6812mini を実装した例です。rev.02以降、SK6812mini は90°回転させて実装します。これは、SK6812mini-E と共存できるようにするためです。**
バックライト用のチップ LED(SK6812mini) は PCB の裏面から実装します。向きに注意して穴に入れてください。
LED の裏から見て、一番大きいパッド（5V）とシルク（印字の事）の○が同じ位置になります。
LED はデータを直列に伝送する都合上、行によって LED の向きが異なります。  
<img width="700" alt="RGB_LED" src="https://github.com/3araht/chromatonemini/blob/main/pictures/LED_serial.jpg">

半田付けが軌道に乗った矢先に向きを間違えがちです。
その時のショックと言ったら。。。（経験者談）。  
<img width="700" alt="RGB_LED" src="https://github.com/3araht/chromatonemini/blob/main/pictures/SK6812mini_alignment.jpg">

温調半田ごてを使い、約220℃で半田付けします。温度が高いとLEDが壊れますので注意してください。
温調できない半田ごてではすぐに焦げます＆壊れます（これも経験者談）。

こてを斜めにして接触面積を広げるとやり易いという事がわかりました。  
<img width="700" alt="RGB_LED" src="https://github.com/3araht/chromatonemini/blob/main/pictures/LED_solder_iron.jpg">

下図の位置を半田でジャンパします。  
<img width="700" alt="Jumper" src="https://github.com/3araht/chromatonemini/blob/main/pictures/LED_jumper_r01.jpg">

LEDの情報は直列に伝送されますので、接続が途切れてしまうと正しくLEDが光らなくなります。

rev.02 以降、下図のように、SK6812mini と SK6812mini-E を共存させることができるようになりました。この例では、SK6812mini と SK6812mini-E を交互に実装しています。
共存させるために、SK6812mini は 90° 回転させて実装します（SK6812mini は従来通り、○ の印字の部分にランドの一番大きな 5V 端子が来るようにします）。  
<img width="700" alt="Jumper" src="https://github.com/3araht/chromatonemini/blob/main/pictures/rev02_LED_TRRS_RESETsw.jpg">  
<img width="700" alt="Jumper" src="https://github.com/3araht/chromatonemini/blob/main/pictures/r02_LED_SK6812miniAndSK6812mini-E.jpg">  

SK6812mini-E は三角のマークの部分に切り欠きの入った端子（GND）が来るように実装します。  
三角マークはLEDの識別番号と重なってしまっていますが。。。  
<img width="700" alt="Jumper" src="https://github.com/3araht/chromatonemini/blob/main/pictures/r02_LED_SK6812mini-E_1.jpg">  
<img width="700" alt="Jumper" src="https://github.com/3araht/chromatonemini/blob/main/pictures/r02_LED_SK6812mini-E_2.jpg">  

## 3 ##
## リセットスイッチ、（rev.02 以降）TRRS コネクタの取付け ##
白い四角い枠のシルクに沿って裏側に取り付けます。浮いたり曲がった状態で実装しないようにマスキングテープなどで予め仮止めしてから半田付けするとミスが少なくなります。  

(rev.02) リセットスイッチの位置が若干変更になっています。  
TRRS コネクタを図のように実装します。また、その下にあるジャンパー2箇所に半田を盛って導通するようにします。  
<img width="700" alt="ResetSW" src="https://github.com/3araht/chromatonemini/blob/main/pictures/rev02_LED_TRRS_RESETsw_soldering.jpg">  

## 4 ##
## Pro Micro 用ピンヘッダの取付け ##
**※コンスルー（スプリングピンヘッダ）を使う場合はこの工程は不要です。**
白い四角い枠のシルクに沿って裏側にピンヘッダを取り付けます。
**この時点で Pro Micro を取り付けてはいけません。一度半田付けしてしまった Pro Micro を取り外すのは至難の技です。充分ご注意ください。**


## 5 ##
## 基板へのスペーサーのネジ止め ##
スペーサーを基板の裏面にネジで26箇所固定します（ネジをオモテ面に挿し、スペーサーが裏面にくるようにします）。  
キースイッチを半田付けした後にはネジを挿入することが難しい箇所があるため、キースイッチを半田付けする前に基板にネジを固定します。  
ただし、半田ごてがスペーサーに触れてしまうとスペーサーが溶けてしまうので、半田付けする際には十分ご注意ください。  
<img width="700" alt="switch" src="https://github.com/3araht/chromatonemini/blob/main/pictures/Spacer_r01.jpg">

## 6 ##
## キースイッチの取付けと、エンコーダの取付け ##
**スイッチを取り付ける前に部品の取付けや半田付けができているか確認します。**  
（1 のダイオードは必ず済ませておいてください。）  

※スプリングピンヘッダを使用する場合は6と8の工程を先に行い、動作確認(下図のようにキースイッチ部をピンセットなどでショートさせ、MIDI機器を認識するソフトで音が出るか確かめる事)をすると失敗する可能性が減ります。  
**動作確認する際には、①HEXファイル書き込み済の Pro Micro を実装し、②USBケーブルをPro Micro に挿して実施してください。**  
<img width="700" alt="switch" src="https://github.com/3araht/chromatonemini/blob/main/pictures/Keysw_test.jpg">

キースイッチをオモテ側からしっかり奥まで差し込みます。このとき、端子が曲がっていると実装穴に端子が入らないので注意してください。1行ずつキースイッチをしっかり差し込んでから半田付けしていった方が差し込み不良は減らせると思います。  
<img width="700" alt="switch" src="https://github.com/3araht/chromatonemini/blob/main/pictures/Keysw_rear_r01.jpg">

ロータリーエンコーダーを実装します。  
<img width="700" alt="RotaryEncorder" src="https://github.com/3araht/chromatonemini/blob/main/pictures/rotary_encorder.jpg">

タクトスイッチも実装します。  
<img width="700" alt="TactSw" src="https://github.com/3araht/chromatonemini/blob/main/pictures/tact_sw.jpg">


## 7 ##
## Pro Micro の取付け ##
**作業前に Pro Micro をUSBでPCと繋げて動作を確認しておきましょう。**
取り付ける前に半田忘れがないか確認します。
取り付けたときに Pro Micro の浮きがないか確認し、浮きがあれば Pro Micro 下のスイッチの足を少しカットします。

**ここでは Pro Micro 基板の下に接続する方法を紹介しますが、もしUSBコネクタがボトムプレートと干渉してしまう場合は、基板の上にPro Microを接続するようにしてください。その場合、コンスルーを半田付けする向きが変わるので十分ご注意ください。**  
<img width="700" alt="CT" src="https://github.com/3araht/chromatonemini/blob/main/pictures/USBconnectorGapCheck.jpg">  

基板の下に配置したときに、USBコネクタがボトムプレートと干渉する場合は下図のように基板の上に ProMicro を配置します。  
<img width="700" alt="CT" src="https://github.com/3araht/chromatonemini/blob/main/pictures/ProMicroOnTop.jpg">

以降、基板の下に Pro Micro を配置するものとして説明します。  

※コンスルーを使う場合は Pro Micro 側のみを半田付けします。  
コンスルーの役割： 基板側を半田付けしないことにより、 Pro Micro を基板から外せるようにします。
これにより、万が一 Pro Micro の microUSB コネクタがもげても交換が容易になります。

<img width="700" alt="CT" src="https://github.com/3araht/chromatonemini/blob/main/pictures/Con_through.jpg">

コンスルーを斜めに半田付けしないように、基板の**裏面から**コンスルーを差しておいてピンが垂直になるようにします。
下図のように、Pro Micro 側(側面に空いている小さな穴が近い方)を上にして基板にコンスルーを差し込みます。
このとき、図のように、コンスルーの向きを揃えておきます（＝2つとも側面の小さな穴が空いている方向を揃えます）。  
<img width="700" alt="CT" src="https://github.com/3araht/chromatonemini/blob/main/pictures/Con_through_onPCB_r01.jpg">

*Pro Micro の上下の向きに注意。Pro Micro の TxD ピンが基板の TxD に刺さるように向きが合っているか確認します。  
<img width="700" alt="CT" src="https://github.com/3araht/chromatonemini/blob/main/pictures/PinAlignment.jpg">  

コンスルーを基板の裏面から差し、TxD の位置を見て向きが揃っていることを確認したら、コンスルーと Pro Micro を半田付けします。  
**Pro Micro が浮きやすいので、Pro Micro をしっかり押さえながら最初に四隅を半田付けすると作業が楽になります。**  
**一度半田付けしたコンスルーを外すのは困難を極めますので、十分注意してください。**

コンスルーを Pro Micro に実装した様子  
<img width="700" alt="CT" src="https://github.com/3araht/chromatonemini/blob/main/pictures/ProMicro_TxD_r02.jpg">    
<img width="700" alt="CT" src="https://github.com/3araht/chromatonemini/blob/main/pictures/ProMicro_front_r02.jpg">    

## 8 ##
## Firmwareの書き込み ##

### 8.1 ###
### コーディングはちょっと自信がない／とりあえず動作させたい、という方 ###

#### 8.1.1 ####
#### とりあえず全部入り版、という方 ####

LEDが光ったり、[下記](https://github.com/3araht/chromatonemini/blob/main/docs/build.md#layers)に示すレイヤーが盛り込まれた全部入り版のHEXファイル(chromatonemini_led.hex)は[こちら](https://github.com/3araht/chromatonemini/blob/main/chromatonemini_led_hex.zip)からダウンロードできます（3araht はこれを使用しております）。  

初めての方はHEXファイルの書き込みに以下のツールを使うことをお勧めします。  

普通の Pro Micro をお使いの場合は Pro Micro Web Updater  
https://sekigon-gonnoc.github.io/promicro-web-updater/index.html
※ どうやら、 Pro Micro を書き込む際に、素早くやらないと、Verify の完了まで行かないようです。  
必ず、ログを確認し、書き込みのみならず Verify まで完了していることを確認しておいてください。

Elite-C をお使いの場合は QMK Toolbox  
https://github.com/qmk/qmk_toolbox

これらの使い方は サリチル酸さんの[記事](https://salicylic-acid3.hatenablog.com/entry/qmk-toolbox)がとても参考になります(サリチル酸さん、どうもありがとうございます)。

#### 8.1.2 ####
#### 全部入り版使った後で、LED光らなくていいし、レイヤーたくさんいらないけど、REMAP でキー配列をちょっと変更したい、という方 ####

MIDIを使ったキーボードなのに、VIA 機能を有効にし、REMAP で動的にキー配列を変更できるようになりました！！！  
一部制限（※）はございますが、MIDI 機能の別のキー（サスティンなど）を割り当てたいけどコーディングは面倒、という方、お待たせしました！  
VIA に対応したファームウェア（[chromatonemini_via.hex](https://github.com/3araht/chromatonemini/blob/main/chromatonemini_via_hex.zip) ）を上で示したツールで書き込んでください。  

ここまでで default のキー配列で動作します。もしキー配列を変更したい場合は、
[REMAP](https://remap-keys.app/) でキー配列を自由に変更することが可能です。  

[REMAP](https://remap-keys.app/) で MIDI 関連のキーにも対応いただいた、Yoichiro さん、ありがとうございました。  

（※）一部制限: VIA は EEPROM を使うため、使えるキーの数＆レイヤーの数に制限があります。そのため、レイヤー数が 4 になっています。  


### 8.2 ###
### コーディングに慣れている方、チャレンジされる方 ###

以下を参考に書き込んでください。または、QMKで検索すると書き込み方がすぐに出てくるはずです。  
https://docs.qmk.fm/#/getting_started_build_tools

chromatonemini の Firmware は以下にUPされるよう push request 中です(まだリンク切れ状態です)。  
https://github.com/qmk/qmk_firmware/tree/main/keyboards/chromatonemini

それまで、暫定的に[こちら](https://github.com/3araht/chromatonemini/blob/main/temp/qmk_firmware/keyboards/chromatonemini)のソースコードをお使いください。

#### 8.2.1 ####
#### 暫定的にUPしたソースの使い方 ####
1. まず、qmk_firmware を clone してきます。
https://github.com/qmk/qmk_firmware

2. qmk_firmware/util/new_keyboard.sh を使って chromatonemini キーボード を新規登録します。以下のコマンドでスクリプトを実行します。  
このコマンドは qmk_firmware フォルダで実行します。  
```
./util/new_keyboard.sh
```
下図の赤い文字にしたがって進めて行きます。こうすると、正式な手続きでchromatonemini キーボードのフォルダが qmk_firmware/keyboards に出来上がります。  
<img width="700" alt="new_keyboard" src="https://github.com/3araht/chromatonemini/blob/main/pictures/new_keyboard.png">  

また、これにより、qmk_firmware フォルダで  

```
make chromatonemini:default
```

などのコンパイルも通るようになります。

3. 暫定的に UP している[こちら](https://github.com/3araht/chromatonemini/blob/main/temp/qmk_firmware/keyboards/chromatonemini)のソースコードを qmk_firmware/keyboards/chromatonemini に上書き保存します。

### 8.3 ###
### defaultのHEXファイル (chromatonemini_via.hex) について ###

エンコーダを右に回すと音量が大きくなり、左に回すと小さくなるようになっています。
エンコーダは押しボタンにもなっており、押すとミュートON/OFFを切り替えるようになっています。

なお、電源を再投入（USB抜き差し）したらデフォルト配列に戻ります。

### 8.4 ###
### 上記全部入り版のHEXファイル (chromatonemini_led.hex) について ###

**全部入り版のHEXファイルは上記に示すdefault 設定に加えて、1. LEDが実装されていれば押したキーのLED が発光、2. Flipレイヤーなどへのレイヤー切り替え、3. オクターブ調整が可能なようになっています。**

#### layers ####

音符のレイアウト一覧  
<img width="700" alt="Layer" src="https://github.com/3araht/chromatonemini/blob/main/pictures/20210501_chromatonemini_notes_layout.png">    

エンコーダボタン長押ししたときの様子 Function(FN) Layer  
<img width="700" alt="Layer" src="https://github.com/3araht/chromatonemini/blob/main/pictures/20210502_chromatonemini_FN_layer.png">    


## 9 ##
## チェックポイント ##
簡単なチェック項目を挙げます。参考になれば幸いです。

【全体】
- Pro Micro はしっかり基板に刺さっている。
- Pro Micro のピンと基板のピンは一致させた状態で接続できている（Pro Micro の上下の向き確認）。
- USB ケーブルは通信可能なものを使っている（充電器の付属品などは要注意）。
- Pro Micro にファームウェアを書き込んである。
- MIDI機器に対応したソフトを起動している。
- 半田付けに問題はないか（ダイオードの向き、赤目、富士山、など）。

【Backlight RGB LED編】  
動作チェック用にUSB繋いだら全てのLEDが最初からカラフルに点灯するファームウェアを作成しました。
スケールインジケーターは非表示にしてあるので、デバッグしやすいかと思います。デバッグの手助けになれば幸いです。  
[chromatonemini_party.hex](https://github.com/3araht/chromatonemini/blob/master/chromatonemini_party_hex.zip)  

以下、チェック項目です。
- テスター（マルチメータ）をお持ちの場合は、基板からProMicro、ケーブル類を全て外した状態で、＋端子を5Vに、−端子をGND に当てて 抵抗測定してみてください。
  ~~もしも 1 MΩ以上の高抵抗値であれば正常。数十 kΩ程度かそれ以下の場合はLEDが一部破損 or LEDの向きが間違っている可能性があります。~~  
  嘘つきました。LED の 5V - GND 端子間の抵抗値が 100 kΩ 程度しか無いので、数十個の LED を並列繋ぎにしているため、抵抗値は 1 kΩ 程度しかありませんでした。  
  ⇨ テスターで 5V - GND 間の抵抗を測定しても、あまり参考にはならないです。
- LEDの向きが正しいか(一番大きいパッド（5V）とシルク（印字の事）の○が同じ位置か確認)。
- 4つの端子が基板にしっかり半田付けできているか。数が多いので、数個半田が甘かった、ということはよくあります。
- あるところから先の LED が全く光らない場合は、その境界のLEDの信号線で半田不良 or LED 破損の可能性があります。
  LED の並びについては、上記 2 Backlight RGB LEDの取付け[Optional] をご覧ください。
- あるところから先の LED の光り方が変な場合は、その境界の LED の電源線（5V か GND）の半田不良 or LED 破損の可能性があります。
- LED は光るものの、他のLEDに比べて暗い場合は、その LED が半田ごてに熱でやられている可能性があります。

また、遊舎工房さんの[サポートサイト](https://yushakobo.zendesk.com/hc/ja)が参考になると思います。併せてご覧ください。

## 10 ##
## ボトムプレートの組み立て ##
全てのキースイッチが正しく動作するのを確認したら、基板に取り付けたスペーサーにボトムプレートを固定します。
ボトムプレートの図の黄色丸の位置 26 箇所に M2 のねじでを挿入して固定します。  
<img width="700" alt="spacer" src="https://github.com/3araht/chromatonemini/blob/main/pictures/BottomPlate_r01.jpg">  

ネジ止めは、たすき掛けで均一に締めつけますが、強く締めつけすぎないようにします。

黄色丸の位置 15 箇所にクッションシールを取り付けます。  
<img width="700" alt="feet" src="https://github.com/3araht/chromatonemini/blob/main/pictures/Cushon_r01.jpg">

#### お疲れ様でした。以上で chromatonemini キーボードの完成です！
