int readImage(Matriz *imageContent, char *pathToImage, char *readingType){
    FILE *fp = fopen(nomeArquivo, readingType);
    int numbers = 0;
    char ch[2];
    int pixel = 0;
    if (fp != NULL){
        while ((ch[0] = fgetc(fp)) != EOF) {
            if (ch[0] != ' ' || ch[0] != '\n') {
                ch[1] = '\0';
                pixel *= 10;
                pixel += atoi(ch);
            } else{
                numbers++;
                vetor_add(v,pixel);
                pixel = 0;
            }
        }
    fclose(fp);
    }
    return numbers;
}
