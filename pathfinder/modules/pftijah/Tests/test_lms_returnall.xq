let $opt := <TijahOptions 
                collection="thesis" 
                txtmodel_model="LMS" 
                txtmodel_returnall="true"
                debug="0"/>

return pf:tijah-query($opt,(),"//section[about(.,pathfinder)]")
