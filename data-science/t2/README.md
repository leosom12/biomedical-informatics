# Ciência de Dados para Segurança 
## Prática 02
Para rodar o script em seu terminal, utilize as seguintes linhas de comando: 
### Parte 1: Análise de APKs
python3 script.py manifests

O diretório manifests contém os AndroidManifests de 11 aplicações diferentes. A seguir encontra-se a lista de apks escolhidas: 
- **Entertainment**
    1. Globoplay 3.109.0 (nodpi) (Android 5.0+)

        [https://www.apkmirror.com/apk/globo-comunicacao-e-participacoes-s-a/globo-play/globo-play-3-109-0-release/globoplay-3-109-0-android-apk-download/download/?forcebaseapk](https://www.apkmirror.com/apk/globo-comunicacao-e-participacoes-s-a/globo-play/globo-play-3-109-0-release/globoplay-3-109-0-android-apk-download/download/?forcebaseapk)

    2. Globoplay 3.100.0 (nodpi) (Android 5.0+)

        [https://www.apkmirror.com/apk/globo-comunicacao-e-participacoes-s-a/globo-play/globo-play-3-100-0-release/globoplay-3-100-0-android-apk-download/download/?forcebaseapk](https://www.apkmirror.com/apk/globo-comunicacao-e-participacoes-s-a/globo-play/globo-play-3-100-0-release/globoplay-3-100-0-android-apk-download/download/?forcebaseapk)

- **Education**
    1. TED 4.5.6 (Android 5.0+)

        [https://www.apkmirror.com/apk/ted-conference/ted/ted-4-5-6-release/ted-4-5-6-android-apk-download/download/](https://www.apkmirror.com/apk/ted-conference/ted/ted-4-5-6-release/ted-4-5-6-android-apk-download/download/)

    2. Udemy - Online Courses 6.18.0 (nodpi) (Android 6.0+)

        [https://www.apkmirror.com/apk/udemy/udemy-online-courses/udemy-online-courses-6-18-0-release/udemy-online-courses-6-18-0-android-apk-download/download/?forcebaseapk](https://www.apkmirror.com/apk/udemy/udemy-online-courses/udemy-online-courses-6-18-0-release/udemy-online-courses-6-18-0-android-apk-download/download/?forcebaseapk)

- **Productive**
    1. Todoist: To-Do List, Tasks & Reminders v7762 (nodpi) (Android 6.0+)

        [https://www.apkmirror.com/apk/doist/todoist/todoist-v7762-release/todoist-to-do-list-tasks-reminders-v7762-android-apk-download/download/?forcebaseapk](https://www.apkmirror.com/apk/doist/todoist/todoist-v7762-release/todoist-to-do-list-tasks-reminders-v7762-android-apk-download/download/?forcebaseapk)

    2. Basecamp 3 3.20.1 (Android 6.0+)

        [https://www.apkmirror.com/apk/basecamp/basecamp-3/basecamp-3-3-20-1-release/basecamp-3-3-20-1-android-apk-download/download/](https://www.apkmirror.com/apk/basecamp/basecamp-3/basecamp-3-3-20-1-release/basecamp-3-3-20-1-android-apk-download/download/)

- **Communication**
    1. WhatsApp Messenger 2.21.4.12 beta (x86_64) (Android 4.1+)

        [https://www.apkmirror.com/apk/whatsapp-inc/whatsapp/whatsapp-2-21-4-12-release/whatsapp-messenger-2-21-4-12-4-android-apk-download/download/](https://www.apkmirror.com/apk/whatsapp-inc/whatsapp/whatsapp-2-21-4-12-release/whatsapp-messenger-2-21-4-12-4-android-apk-download/download/)

    2. Telegram 7.4.2 (Android 4.1+)

        [https://www.apkmirror.com/apk/telegram-fz-llc/telegram/telegram-7-4-2-release/telegram-7-4-2-8-android-apk-download/download/](https://www.apkmirror.com/apk/telegram-fz-llc/telegram/telegram-7-4-2-release/telegram-7-4-2-8-android-apk-download/download/)

- **Books & Reference**
    1. @Voice Aloud Reader (TTS Reader) 22.6.7 (nodpi)
    2. Audible: audiobooks, podcasts & audio stories 2.67.2 (Android 4.1+)
- **Art & Design**
    1. Canva: Graphic Design, Video Collage, Logo Maker 2.98.2 (Android 5.0+)

        [https://www.apkmirror.com/apk/canva/canva-free-photo-editor-graphic-design-tool/canva-free-photo-editor-graphic-design-tool-2-98-2-release/canva-graphic-design-video-collage-logo-maker-2-98-2-android-apk-download/download/](https://www.apkmirror.com/apk/canva/canva-free-photo-editor-graphic-design-tool/canva-free-photo-editor-graphic-design-tool-2-98-2-release/canva-graphic-design-video-collage-logo-maker-2-98-2-android-apk-download/download/)
        
### Parte 2: Análise de arquivos PE
**Script 1:**

python3 script01.py exe

O diretório exe contém 5 aplicações executáveis diferentes. Os arquivos '.exe' são:
- **BitTorrent.exe**
- **calc.exe**
- **mspaint.exe**
- **WhatsApp.exe**
- **Zoom.exe**

**Script 2:**

Nesta linha de comando os arquivos '.exe' podem ser modificados para qualquer uma das opções contidas no diretório exe. 

Exemplos:

python3 script02.py exe BitTorrent.exe Zoom.exe

python3 script02.py exe BitTorrent.exe calc.exe

python3 script02.py exe mspaint.exe Zoom.exe

## Especificação
### Parte 1: Análise de APKs 

Obtenha ao menos 10 APKs de, no mínimo, três categorias diferentes (https://www.apkmirror.com/categories/) para compor seu dataset cru.

Para cada APK coletada, extraia o arquivo AndroidManifest.xml em um diretório "manifests", lembrando de identificar o arquivo resultante (por exemplo, se sua APK se chama 'BancoX-v01.apk', nomeie o manifesto como 'AndroidManifest_BancoX-v01.xml').

Escreva um script em Python (ou um ipynb) que, dado um diretório como argumento de entrada, retorne a lista de permissões de cada AndroidManifest.xml sob a forma de um dicionário (chave: nome da APK, valor: lista de permissões). Exemplo de saída impressa no terminal desta parte do script:

'===================

Permissões por APK

==================='

BancoX-v01: ['WRITE_SETTINGS', 'READ_APP_BADGE']

...

InstantMessengerY-101010: ['SEND_SMS', 'WRITE_SETTINGS']

No mesmo script, faça uma função que retorne a lista de permissões únicas de cada APK e comuns a todas as APKs analisadas (intersecção). Exemplo de saída impressa no terminal desta parte do script:

'==================='

Permissões únicas por APK

'==================='

BancoX-v01: ['READ_APP_BADGE']

...

InstantMessengerY-101010: ['SEND_SMS']

'===================

Permissões comuns das APKs

==================='

['WRITE_SETTINGS']

### Parte 2: Análise de arquivos PE
Obtenha alguns binários de Windows (você pode pegá-los do seu próprio computador, se tiver o sistema operacional instalado, ou de sites de download de programas, como sourceforge e outros). Exemplos de binários: calc.exe, ping.exe, paint.exe, netstat.exe...

Escreva um script em Python (ou .ipynb) que receba como entrada um arquivo ou diretório e enumere a seções executáveis do(s) binário(s), imprimindo na saída padrão um dicionário de listas, onde a chave é o nome do binário e o valor é uma lista de seções executáveis. Dica: https://github.com/erocarrera/pefile

Escreva outro script em Python (ou .ipynb) que receba como entrada dois arquivos .exe e os compare, imprimindo na saída padrão quais seções são comuns a ambos os binários, quais somente estão presentes no binário 1 e quais somente estão presentes no binário 2. Siga as regras de formato/apresentação já estabelecidas nesta tarefa.


