# python下载网页生成mobi格式电子书

## 1.python下载网页
```py
import urllib.request

def getHtml(url):
    html = urllib.request.urlopen(url).read()
    return html

def saveHtml(file_name, file_content):
    # 注意windows文件命名的禁用符，比如 /
    with open(file_name.replace('/', '_') + ".html", "wb") as f:
        # 写文件用bytes而不是str，所以要转码
        f.write(file_content)

#https://bibletruth.cn/1n1bB/ynyb_B_335.html
aurl = "https://bibletruth.cn/1n1bB/ynyb_B_"

index_html="<html><body>"
for i in range(335,366):
    page_url=aurl+str(i)+".html"   
    html = getHtml(page_url)
    saveHtml(str(i), html)
    index_html+="<a href='"+str(i)+".html'>"+str(i)+"</a></br>"   

index_html+="</body></html>"
f = open("index.html",'w')
f.write(index_html)
f.close()

```

## 2.calibre生成mobi
[书伴繁简转换](https://bookfere.com/post/162.html)
