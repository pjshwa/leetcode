import java.util.*;

class FileSystem {
    private HashMap<String, Integer> pathStore;
  
    public FileSystem() {
      pathStore = new HashMap<String, Integer>();
      pathStore.put("", -1);
    }

    public boolean createPath(String path, int value) {
      // last occurence of '/' in path
      int sIdx = -1;
      for (int i = 0; i < path.length(); i++) {
        char c = path.charAt(i);
        if (c == '/') sIdx = i;
      }
      
      String parent = path.substring(0, sIdx);
      
      // parent path doesn't exist
      if (!pathStore.containsKey(parent)) return false;

      // path already exists
      if (pathStore.containsKey(path)) return false;
      
      // create a new path and associate value
      pathStore.put(path, value);
      return true;
    }

    public int get(String path) {
      return pathStore.getOrDefault(path, -1);
    }
}
