# Ciência de Dados para Segurança 
## Prática 02
Para rodar o script em seu terminal, utilize as seguintes linhas de comando: 
### Parte 1: Análise de APKs
<p align="center"> python3 script.py manifests </p>

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

<p align="center"> python3 script01.py exe </p>

O diretório exe contém 5 aplicações executáveis diferentes. Os arquivos '.exe' são:
- **BitTorrent.exe**
- **calc.exe**
- **mspaint.exe**
- **WhatsApp.exe**
- **Zoom.exe**

**Script 2:**

Nesta linha de comando os arquivos '.exe' podem ser modificados para qualquer uma das opções contidas no diretório exe. 

Exemplos:

<p align="center"> python3 script02.py exe BitTorrent.exe Zoom.exe </p>

<p align="center"> python3 script02.py exe BitTorrent.exe calc.exe </p>
 
<p align="center"> python3 script02.py exe mspaint.exe Zoom.exe </p>
