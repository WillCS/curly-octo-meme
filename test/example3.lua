function entry1 (o)
    N=N + 1
    local title = o.title or o.org or 'org'
    fwrite('<HR>\n<H3>\n')
    local href = ''
  
    if o.url then
      href = string.format(' HREF="%s"', o.url)
    end
    fwrite('<A NAME="%d"%s>%s</A>\n', N, href, title)
  
    if o.title and o.org then
      fwrite('<BR>\n<SMALL><EM>%s</EM></SMALL>', o.org)
    end
    fwrite('\n</H3>\n')
  
    if o.description then
      fwrite('%s', string.gsub(o.description,
                               '\n\n\n*', '<P>\n'))
      fwrite('<P>\n')
    end
  
    if o.email then
      fwrite('Contact: <A HREF="mailto:%s">%s</A>\n',
             o.email, o.contact or o.email)
    elseif o.contact then
      fwrite('Contact: %s\n', o.contact)
    end
  end