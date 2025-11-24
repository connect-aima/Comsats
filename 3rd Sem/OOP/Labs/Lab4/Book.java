class Book {
    private String author;
    private String[] chapterNames;

    public Book() {
        this.author = "";
        this.chapterNames = new String[100];
    }

    public Book(String author, String[] chapterNames) {
        this.author = author;
        this.chapterNames = chapterNames;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public void setChapterNames(String[] chapterNames) {
        this.chapterNames = chapterNames;
    }

    
    public String getAuthor() {
        return author;
    }

    public String[] getChapterNames() {
        return chapterNames;
    }

   
    public boolean compareBooks(Book b) {
        return this.author.equalsIgnoreCase(b.author);
    }

    
    public Book compareChapterNames(Book b) {
        int thisCount = 0, bCount = 0;

       
        for (String ch : this.chapterNames) {
            if (ch != null)
                thisCount++;
        }

       
        for (String ch : b.chapterNames) {
            if (ch != null)
                bCount++;
        }

       
        if (thisCount >= bCount) {
            return this;
        } else {
            return b;
        }
    }
}
