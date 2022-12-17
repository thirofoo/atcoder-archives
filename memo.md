## github で GPG(GnuGP GNU Privacy Guard) 利用
そもそも GPG とは : 暗号化ソフト
GPGを用いると、応用情報で習ったような暗号化や電子署名が可能。

GPG には 公開鍵と秘密鍵がある。
公開鍵をgithubのaccountに紐づけて、秘密鍵をcommitする時に署名用に用いることで、
commitに電子署名が付与されて "Verified" と付く(認められたcommitですよー的な)

秘密鍵で署名を書くことで、赤の他人が自分の公開鍵を用いて復号することで自分のcommitで有ることを証明している。

上記の様な流れで鍵の設定を行う。
[参考文献1 : Githubに署名付きコミットしてみた https://zenn.dev/appare45/articles/github-commit-sign]
[参考文献2 : GPGkey削除方法 https://zenn.dev/noraworld/articles/delete-gpg-keys]
[参考文献3 : GPGPrivateKeyを取得 https://qiita.com/cappyzawa/items/8be66af768c11c45f414#gpg-private-key%E3%82%92%E5%8F%96%E5%BE%97%E3%81%99%E3%82%8B]

※参考文献1を最初からやれば基本行けるはず
① 公開鍵を作成して、github account に紐づける
② commit 時に署名を行うか や 使用する鍵を指定 などの設定をする (git config ~ )

今回見たいにgithub actions での workflow 内のコミットでも署名したい時は、actions の secrets に、
GPG＿PRIVATE＿KEY と言う名前で秘密鍵を登録しておく。(秘密鍵の取得は参考文献3にて)


今回はkeyを作成した後に、commitしようとしてもgpg でサイン出来ないとエラーを吐かれ、
ネット上にあるどれをやっても無理だったが、
各鍵にはpermissionがあり、そこを付けたり消したりしてたら何故か通るようになった(?)
あとサブkeyのsignの権限を付加すると、github側が変な認識をして署名出来ない出来な記事もどこかで見た。
