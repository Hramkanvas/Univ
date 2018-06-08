package pack;

import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;

public class MClasses {
    private List<MClass> mClassList;
    private List<String> allTokensList;
    private Map<String, Integer> tokensMap;

    public MClasses(Paths paths) throws FileNotFoundException {
        mClassList = new ArrayList<>();
        allTokensList = new ArrayList<>();
        for (int i = 0, size = paths.getPathList().size(); i < size; i++) {
            mClassList.add(new MClass(paths.getPathList().get(i)));
            allTokensList.addAll(mClassList.get(i).getTokenList());
        }
    }

    public void sortAllTokensList() {
        allTokensList.sort(new TokensComparator());
    }

    public void writeList(String path) throws FileNotFoundException {
        Iterator<String> iterator = allTokensList.iterator();
        try (PrintStream printStream = new PrintStream(path)) {
            while (iterator.hasNext()) {
                printStream.printf("%s\n\n", iterator.next());
            }
        }
    }

    public void setTokensMap() {
        tokensMap = new HashMap<>();
        for (String item : allTokensList) {
            if (tokensMap.containsKey(item)) {
                tokensMap.put(item, tokensMap.get(item) + 1);
            } else {
                tokensMap.put(item, 1);
            }
        }
    }

    public void writeMap(String path) throws FileNotFoundException {
        try (PrintStream printStream = new PrintStream(path)) {
            for (Map.Entry<String, Integer> entry : tokensMap.entrySet()) {
                printStream.printf("\nToken: \n %s \nthe number of tokens of this type = %d\n", entry.getKey(), entry.getValue());
            }
        }
    }
}
